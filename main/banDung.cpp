#include <avr/interrupt.h>
#include <EEPROM.h>
#include <RobotControl.h>
#include <LedControl.h>

#define BUTTON1 7   // nút nhấn 1
#define BUTTON2 8   // nút nhấn 2
#define BUTTON3 12  // nút nhấn 3
#define BUZZER 4    // chân điều khiển loa

RobotControl motor;
LedControl LedControl;
//---------------------------------------------------
volatile int lastPos;
volatile unsigned char isCalib = 0;
volatile int servoPwm;
volatile unsigned char sensor;
unsigned int sensorValue[8];
unsigned int sensorPID[8];
unsigned int black_value[8];
unsigned int white_value[8];
unsigned int compare_value[8];
int speed_run_forward;
int cnt = 0;
unsigned char pattern, start;
int line = 0;
int RememberLine = 0;
int kp;
int kd;

void setup() {
  motor.begin();
  LedControl.begin();
  //---------------PWM------------------------//
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  //-------------------------------------------------//
  //CÀI ĐẶT CÁC THÔNG SỐ BAN ĐẦU
  speed_run_forward = 20;  //bạn thay đổi tốc độ ở đây, tốc độ chạy max 255, min 10
  motor.speed_run(0, 0);         // dừng 2 bánh
  pattern = 10;            // set trạng thái chạy
  start = 0;               // Trước khi chạy học màu lại, đưa cảm biến qua lại trên đường line rồi bấm SW1 để lưu
  readEeprom();
  Serial.begin(9600);
  //-------------------------------------------------//
  for (int i = 2000; i < 3500; i += 500) {
    tone(BUZZER, i, 100);
    delay(100);
  }
  timer_init();
  isCalib = 1;
  pinMode(BUZZER, OUTPUT);
  //-------------------------------------------------//
}
void timer_init() {
  // Timer/Counter 2 initialization
  ASSR = (0 << EXCLK) | (0 << AS2);
  TCCR2A = (0 << COM2A1) | (0 << COM2A0) | (0 << COM2B1) | (0 << COM2B0) | (0 << WGM21) | (0 << WGM20);
  TCCR2B = (0 << WGM22) | (1 << CS22) | (1 << CS21) | (1 << CS20);
  TCNT2 = 0xB2;
  OCR2A = 0x00;
  OCR2B = 0x00;
  // Timer/Counter 2 Interrupt(s) initialization
  TIMSK2 = (0 << OCIE2B) | (0 << OCIE2A) | (1 << TOIE2);
}
ISR(TIMER2_OVF_vect) {
  TCNT2 = 0xB2;
  read_sensor();
  cnt++;
}
void loop()  // vòng lặp, không dùng delay() trong này
{
  while (start == 0)  // nhấn nút để chạy
  {
    updateLine();                     // học màu, nhấn SW1 để lưu cảm biến
    if (digitalRead(BUTTON1) == 0) {  // Nhấn SW3 để chạy
      start = 1;                      // học màu xong va bắt đầu chạy
      isCalib = 0;
      cnt = 0;
      speed_run_forward = 80;
    }
    if (digitalRead(BUTTON2) == 0) {  // Nhấn SW3 để chạy
      start = 1;                      // học màu xong va bắt đầu chạy
      isCalib = 0;
      cnt = 0;
      speed_run_forward = 110;
    }
    if (digitalRead(BUTTON3) == 0) {  // Nhấn SW3 để chạy
      start = 1;                      // học màu xong va bắt đầu chạy
      isCalib = 0;
      cnt = 0;
      speed_run_forward = 130;
    }
  }

  switch (pattern) {  // đoạn mã trạng thái máy
    case 10:
      // if (cnt >= speed_run_forward) {  // KHởi động mềm
      //   pattern = 11;
      //   cnt = 0;
      //   break;
      // }
      if (cnt >= 100) {  // KHởi động mềm
        pattern = 11;
        cnt = 0;
        break;
      }
      runforwardline(100);
      break;
    case 11:
      if (sensorMask(0x81) == 0x81) {
        pattern = 100;
        break;
      }
      if (sensorMask(0x01) == 0x01) {
        RememberLine = 1;
        cnt = 0;
      } else if (sensorMask(0x80) == 0x80) {
        RememberLine = -1;
        cnt = 0;
      }
      if (cnt > 200) RememberLine = 0;
      if (sensor == 0x00) {
        if (RememberLine != 0) {
          pattern = 12;
        } else {
          motor.speed_run(0, 0);
        //  pattern = 100;
        }
        break;
      } else runforwardline(speed_run_forward);
      break;
    case 12:
      if (RememberLine == 1) {
        motor.speed_run(speed_run_forward, -40);
        pattern = 21;
        break;
      } else if (RememberLine == -1) {
        motor.speed_run(-40, speed_run_forward);
        pattern = 31;
        break;
      } else {
        pattern = 11;
        break;
      }
    case 21:
      motor.speed_run(speed_run_forward, -40);
      LedControl.RGB(1);
      if (sensorMask(0x01) != 0) {
        motor.speed_run(speed_run_forward, speed_run_forward / 2);
        pattern = 22;
      }
      break;
    case 22:
      motor.speed_run(speed_run_forward, speed_run_forward / 2);
      LedControl.RGB(1);
      if (sensorMask(0x18) != 0) {
        pattern = 11;
        // RememberLine = 0;
        // line = 0;
      }
      break;


    case 31:
      motor.speed_run(-40, speed_run_forward);
      LedControl.RGB(2);
      if (sensorMask(0x80) != 0) {
        motor.speed_run(speed_run_forward / 2, speed_run_forward);
        pattern = 32;
      }
      break;
    case 32:
      motor.speed_run(speed_run_forward / 2, speed_run_forward);
      LedControl.RGB(2);
      if (sensorMask(0x18) != 0) {
        pattern = 11;
        // RememberLine = 0;
        // line = 0;
      }
      break;
    case 100:
      motor.speed_run(0, 0);
      LedControl.RGB(millis() / 100 % 3);
      break;
    default:
      pattern = 11;
      break;
  }
}
///////////////////////////////////////////////////////////////////////
void runforwardline(int tocdo)  // hàm chạy bám line
{
  switch (sensor) {
    case 0b00000000:
      // kd = 12;
      // if (RememberLine == 1) line = 3;
      // if (RememberLine == -1) line = -3;
      // if (line > 0) {
      //   // SpeedSpectilize(90, 0);
      //   motor.speed_run(100, -40);
      //   LedControl.RGB(1);
      // } else if (line < 0) {
      //   //  SpeedSpectilize(-90, 0);
      //   motor.speed_run(-40, 100);
      //   LedControl.RGB(2);
      // } else {
      //   motor.speed_run(0, 0);
      //   LedControl.RGB(0);
      // }
      motor.speed_run(0, 0);
      break;
    case 0b00011000:
    case 0b00001000:
    case 0b00010000:
    case 0b00111000:
    case 0b00011100:
      kd = 12;
      LedControl.RGB(0);
      line = 0;
      SpeedSpectilize(servoPwm, tocdo + 10);
      break;
    case 0b00111100:
    case 0b00111110:
    case 0b01111110:
      kd = 12;
      LedControl.RGB(4);
      line = 0;
      SpeedSpectilize(servoPwm, tocdo);
      break;

      ///////////////////////////////////////////////////////////////////////
    case 0b00001100:
    case 0b00000100:
    case 0b00001110:
    case 0b00011110:
      kd = 12;
      line = 1;
      SpeedSpectilize(servoPwm, tocdo);
      break;
    case 0b00000110:
    case 0b00000010:
    case 0b00000111:
      kd = 12;
      line = 2;
      SpeedSpectilize(servoPwm, tocdo);
      break;
    case 0b00000011:
    case 0b00000001:
    case 0b00001111:
    case 0b00011111:
    case 0b00111111:
      kd = 12;
      line = 3;
      SpeedSpectilize(servoPwm, tocdo);
      break;
      /////////////////////////////////////////////////////////////////////

    case 0b00110000:
    case 0b00100000:
    case 0b01110000:
    case 0b01111000:
      kd = 12;
      line = -1;
      SpeedSpectilize(servoPwm, tocdo);
      break;
    case 0b01100000:
    case 0b01000000:
    case 0b11100000:
      kd = 12;
      line = -2;
      SpeedSpectilize(servoPwm, tocdo);
      break;
    case 0b11000000:
    case 0b10000000:
    case 0b11110000:
    case 0b11111000:
    case 0b11111100:
      kd = 12;
      line = -3;
      SpeedSpectilize(servoPwm, tocdo);
      break;

      /////////////////////////////////////////////////////////////////
    default:
      SpeedSpectilize(0, 0);
      break;
  }
}
//--------------------------------------------------------------------------//
void updateLine() {
 // Serial.println(sensor, BIN);
  if (sensor == 0xff) beep(100);
  for (int i = 0; i < 8; i++) {
      Serial.print(sensorValue[i]);
      Serial.print("  ");
    if (black_value[i] == 0) black_value[i] = 1100;
    if (sensorValue[i] < black_value[i]) black_value[i] = sensorValue[i];
    if (sensorValue[i] > white_value[i]) white_value[i] = sensorValue[i];
    compare_value[i] = (black_value[i] + white_value[i]) / 2;
  }
   Serial.println();
  LedControl.RGB(millis() / 100 % 3);
}

void readEeprom() {
  for (int i = 0; i < 8; i++) {
    compare_value[i] = EEPROM.read(i) * 4;
  }
}
//-------------------------------------------------------------------//

//---------------------------------------------------------------------------//
void SpeedSpectilize(int angle, int speed1) {
  int speedLeft;
  int speedRight;
  if ((speed1 + angle) > 255) {
    speed1 = 255 - angle;
  }
  if ((speed1 - angle) > 255) {
    speed1 = 255 + angle;
  }
  speedLeft = speed1 + angle;
  speedRight = speed1 - angle;
  motor.speed_run(speedLeft, speedRight);
}
//---------------------------------------------------------------------------//
//-----------------------------------------------------------//
void read_sensor()  // hàm đọc cảm biến
{
  unsigned char temp = 0;
  unsigned int sum = 0;
  unsigned long avg = 0;
  int i, iP, iD;
  int iRet;
  sensorValue[0] = 1023 - analogRead(A0);
  sensorValue[1] = 1023 - analogRead(A1);
  sensorValue[2] = 1023 - analogRead(A2);
  sensorValue[3] = 1023 - analogRead(A3);
  sensorValue[4] = 1023 - analogRead(A4);
  sensorValue[5] = 1023 - analogRead(A5);
  sensorValue[6] = 1023 - analogRead(A6);
  sensorValue[7] = 1023 - analogRead(A7);
  for (int j = 0; j < 8; j++) {
    if (isCalib == 0) {
      if (sensorValue[j] < black_value[j])
        sensorValue[j] = black_value[j];
      if (sensorValue[j] > white_value[j])
        sensorValue[j] = white_value[j];
      sensorPID[j] = map(sensorValue[j], black_value[j], white_value[j], 0, 1000);
    }
    temp = temp << 1;
    if (sensorValue[j] > compare_value[j]) {
      temp |= 0x01;
    } else {
      temp &= 0xfe;
    }
    sensor = temp;
  }
  for (int j = 0; j < 8; j++) {
    avg += (long)(sensorPID[j]) * ((j)*1000);
    sum += sensorPID[j];
  }
  i = (int)((avg / sum) - 3500);
  kp = 1;
  //kd = 12;
  iP = kp * i;
  iD = kd * (lastPos - i);
  iRet = (iP - iD);
  if ((iRet < -4000)) {
    iRet = 0;
  }
  servoPwm = iRet / 25;//25
  lastPos = i;
}
void beep(int timer) {
  digitalWrite(BUZZER, 1);
  delay(timer);
  digitalWrite(BUZZER, 0);
}
unsigned char sensorMask(unsigned char mask) {
  return (sensor & mask);
}
int check90() {
  if (sensorMask(0x0f)) return 1;
  if (sensorMask(0xf0)) return -1;
}
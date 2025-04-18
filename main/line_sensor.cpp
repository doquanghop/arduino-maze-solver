#include "line_sensor.h"


// Khai báo chân cảm biến
const int sensors[5] = { 2, 3, 4, 5, 6 };
int sensorValues[5];



// Biến điều khiển mất line
unsigned long lostLineTime = 0;
bool lostLine = false;

void initSensors() {
  for (int i = 0; i < 5; i++) {
    pinMode(sensors[i], INPUT);
  }
}

void readSensors() {
  for (int i = 0; i < 5; i++) {
    sensorValues[i] = digitalRead(sensors[i]);
    Serial.print(sensorValues[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void handleLine() {
  readSensors();

  int S1 = sensorValues[0];
  int S2 = sensorValues[1];
  int S3 = sensorValues[2];
  int S4 = sensorValues[3];
  int S5 = sensorValues[4];

  // Trường hợp mất line hoàn toàn
  if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 0) {
    if (!lostLine) {
      lostLineTime = millis();
      lostLine = true;
    }

    if (millis() - lostLineTime > 2000) {  // Nếu mất vạch quá 2 giây
      // Thử quay sang phải nếu không tìm được line sau khi quay trái
      if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 0 && S5 == 0) {
        motor.turnRight(150);  // Quay phải để tìm lại line
      } else {
        motor.turnLeft(150);  // Nếu không quay phải được, thử quay trái
      }
    }
    return;
  }

  // Có line trở lại
  lostLine = false;

  // Điều hướng dựa trên trạng thái cảm biến
  if (S1 == 1 && S2 == 1 && S3 == 0 && S4 == 1 && S5 == 1) {
    motor.moveForward(150);
  } else if ((S1 == 1 && S2 == 0 && S3 == 0 && S4 == 1 && S5 == 1) || (S1 == 0 && S2 == 0 && S3 == 1 && S4 == 1 && S5 == 1)) {
    motor.turnLeft(150);
  } else if ((S1 == 1 && S2 == 1 && S3 == 0 && S4 == 0 && S5 == 1) || (S1 == 1 && S2 == 1 && S3 == 1 && S4 == 0 && S5 == 0)) {
    motor.turnRight(150);
  } else if (S1 == 1 && S2 == 1 && S3 == 1 && S4 == 1 && S5 == 1) {
    motor.stop();
  } else {
    motor.moveForward(150);  
  }

  // Xử lý ngã ba hoặc ngã tư
  if (S1 == 0 && S2 == 1 && S3 == 0 && S4 == 1 && S5 == 0) {
    if (S3 == 0) {
      if (S1 == 0) {
        motor.turnLeft(150);
      } else if (S5 == 0) {
        motor.turnRight(150);
      }
    } else {
      motor.moveForward(150);
    }
  }
}

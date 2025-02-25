#include "motor_control.h"

MotorControl::MotorControl(int m1p1, int m1p2, int m2p1, int m2p2, int sp1, int sp2) {
    // TODO: Khởi tạo chân động cơ
    
    // Gán giá trị chân điều khiển
    this->motor1Pin1 = m1p1;
    this->motor1Pin2 = m1p2;
    this->motor2Pin1 = m2p1;
    this->motor2Pin2 = m2p2;
    this->motorSpeedPin1 = sp1;
    this->motorSpeedPin2 = sp2;

    // Cấu hình chân xuất tín hiệu
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motorSpeedPin1, OUTPUT);
    pinMode(motorSpeedPin2, OUTPUT);


}

void MotorControl::moveForward(int speed) {
    // TODO: Hàm điều khiển tiến
    speed = constrain(speed, 0, 255);

    digitalWrite(motor1Pin1, HIGH); //chân điểu khiển
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin1, speed); // cđiều khiển tín hiệu bằng PWM
    analogWrite(motorSpeedPin2, speed);  


}

void MotorControl::moveBackward(int speed) {
    // TODO: Hàm điều khiển lùi
    speed = constrain(speed, 0, 255);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin1, speed);
    analogWrite(motorSpeedPin2, speed);
}

void MotorControl::turnLeft(int speed) {
  // Hàm điều khiển rẽ trái
    moveStop();
    delay(100); 
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    speed = constrain(speed, 0, 255);
    analogWrite(motorSpeedPin1, speed/2);  // dừng bánh trái
    analogWrite(motorSpeedPin2, speed);
    delay(600);
    moveStop();
}

void MotorControl::turnRight(int speed) {
  // Hàm điều khiển rẽ phải
    moveStop();
    delay(100); 
    digitalWrite(motor1Pin1,HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    speed = constrain(speed, 0, 255);
    analogWrite(motorSpeedPin1, speed);  
    analogWrite(motorSpeedPin2, speed/2);
    delay(600);
    moveStop();
}

void MotorControl::moveStop() {
  // hàm điều khiển dừng
  // dừng cả 2 bánh
    
    digitalWrite(motor1Pin1, LOW); //chân điểu khiển
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin1, 0);  
    analogWrite(motorSpeedPin2, 0);
      
}

void MotorControl::rotate180(int speed) {
    moveStop();
    delay(100); 

    // Quay phải 180 độ
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);

    speed = constrain(speed, 0, 255);
    analogWrite(motorSpeedPin1, speed);
    analogWrite(motorSpeedPin2, speed);

    delay(1000);  

    moveStop();  
}

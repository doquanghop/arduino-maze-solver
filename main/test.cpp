#include "huce_motor.h"
MotorControl::MotorControl(int m1p1, int m1p2, int m2p1, int m2p2, int sp1, int sp2) {
  motor1Pin1 = m1p1; motor1Pin2 = m1p2, motor2Pin1 = m2p1, motor2Pin2 = m2p2;
  motorSpeedPin1 = sp1, motorSpeedPin2 = sp2;
}

void MotorControl::moveForward() {
  Serial.print("Hello, ");
}

void MotorControl::moveBackward() {
  
}

void MotorControl::moveLeft() {
    // TODO: Hàm điều khiển lùi
}
void MotorControl::moveRight() {
    // TODO: Hàm điều khiển lùi
}
void MotorControl::moveStop() {
    // TODO: Hàm điều khiển lùi
}

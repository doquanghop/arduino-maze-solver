#include "motor_control.h"

MotorControl::MotorControl(int m1p1, int m1p2, int m2p1, int m2p2, int sp1, int sp2) {
    motor1Pin1 = m1p1;
    motor1Pin2 = m1p2;
    motor2Pin1 = m2p1;
    motor2Pin2 = m2p2;
    motorSpeedPin1 = sp1;
    motorSpeedPin2 = sp2;

    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motorSpeedPin1, OUTPUT);
    pinMode(motorSpeedPin2, OUTPUT);
}

void MotorControl::moveForward(int speed) {
  // speed = constrain(speed, 0, 255);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin1, speed);
    analogWrite(motorSpeedPin2, speed);
}

void MotorControl::moveBackward(int speed) {
  // speed = constrain(speed, 0, 255);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin1, speed);
    analogWrite(motorSpeedPin2, speed);
}

void MotorControl::turnLeft(int speed) {
  speed = constrain(speed, 0, 255);
    moveStop();
    delay(100);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin1, speed / 2);
    analogWrite(motorSpeedPin2, speed);
    delay(600);
    // moveStop();
}

void MotorControl::turnRight(int speed) {
  speed = constrain(speed, 0, 255);
    moveStop();
    delay(100);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin1, speed);
    analogWrite(motorSpeedPin2, speed / 2);
    delay(600);
    moveStop();
}

void MotorControl::moveStop() {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin1, 0);
    analogWrite(motorSpeedPin2, 0);
}

void MotorControl::rotate180(int speed) {
  speed = constrain(speed, 0, 255);
    moveStop();
    delay(100);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin1, speed);
    analogWrite(motorSpeedPin2, speed);
    delay(1000);
    moveStop();
}

#include "MotorControl.h"

MotorControl::MotorControl(int m1p1, int m1p2, int m2p1, int m2p2, int sp1, int sp2)
{
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

    analogWrite(motorSpeedPin1, 0);
    analogWrite(motorSpeedPin2, 0);
}

void MotorControl::moveForward(int speed)
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    analogWrite(motorSpeedPin1, constrain(speed, 0, 255));

    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin2, constrain(speed, 0, 255));
}

void MotorControl::moveBackward(int speed)
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    analogWrite(motorSpeedPin1, constrain(speed, 0, 255));

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin2, constrain(speed, 0, 255));
}

void MotorControl::stop()
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    analogWrite(motorSpeedPin1, 0);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin2, 0);
}

void MotorControl::turnRight(int speed)
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    analogWrite(motorSpeedPin1, constrain(speed, 0, 255));

    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(motorSpeedPin2, constrain(speed, 0, 255));
}

void MotorControl::turnLeft(int speed)
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    analogWrite(motorSpeedPin1, constrain(speed, 0, 255));

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(motorSpeedPin2, constrain(speed, 0, 255));
}
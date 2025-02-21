#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

class MotorControl {
public:
    MotorControl(int m1p1, int m1p2, int m2p1, int m2p2, int sp1, int sp2);
    void moveForward(int speed);
    void moveBackward(int speed);
    void moveLeft();  // thêm
    void moveRight(); //thêm
    void stop();  // thêm

private:
    int motor1Pin1, motor1Pin2, motor2Pin1, motor2Pin2;
    int motorSpeedPin1, motorSpeedPin2;
};

#endif

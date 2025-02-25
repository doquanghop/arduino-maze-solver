#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

class MotorControl {
public:
    MotorControl(int m1p1, int m1p2, int m2p1, int m2p2, int sp1, int sp2);
<<<<<<< HEAD
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void moveStop();
=======
    void moveForward(int speed);
    void moveBackward(int speed);
    void moveStop();
    void turnLeft(int speed);
    void turnRight(int speed);

>>>>>>> 27e9da0c3e14a908a594e5258256746106bae135

private:
    int motor1Pin1, motor1Pin2, motor2Pin1, motor2Pin2;
    int motorSpeedPin1, motorSpeedPin2;
    bool goesForward = false;
};

#endif

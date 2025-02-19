#ifndef OBSTACLE_AVOIDANCE_H
#define OBSTACLE_AVOIDANCE_H

#include "motor_control.h"
#include "obstacle_sensor.h"

class ObstacleAvoidance {
public:
    ObstacleAvoidance(MotorControl* motor, ObstacleSensor* sensor);
    void checkAndAvoid();

private:
    MotorControl* motor;
    ObstacleSensor* sensor;
};

#endif
#ifndef OBSTACLE_AVOIDANCE_H
#define OBSTACLE_AVOIDANCE_H

#include "modules/motor_control/MotorControl.h"
#include "modules/obstacle_sensor/ObstacleSensor.h"

class ObstacleAvoidance {
public:
    ObstacleAvoidance(MotorControl* motor, ObstacleSensor* sensor);
    void checkAndAvoid();

private:
    MotorControl* motor;
    ObstacleSensor* sensor;
};

#endif
#include "motor_control/MotorControl.h"
#include "obstacle_sensor/ObstacleSensor.h"
#include "obstacle_avoidance/ObstacleAvoidance.h"

MotorControl motor(MOTOR1_PIN1, MOTOR1_PIN2, MOTOR2_PIN1, MOTOR2_PIN2, MOTOR_SPEED_PIN1, MOTOR_SPEED_PIN2);
ObstacleSensor sensor(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
ObstacleAvoidance obstacleAvoidance(&motor, &sensor);

void setupRobot() {
    Serial.begin(9600);
}

void loopRobot() {
    obstacleAvoidance.checkAndAvoid();
}
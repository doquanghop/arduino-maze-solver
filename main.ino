#include "config/Constants.h"
#include "modules/motor_control/motor_control.h"
#include "modules/obstacle_sensor/obstacle_sensor.h"
#include "obstacle_avoidance.h"

MotorControl motor(MOTOR1_PIN1, MOTOR1_PIN2, MOTOR2_PIN1, MOTOR2_PIN2, MOTOR_SPEED_PIN1, MOTOR_SPEED_PIN2);
ObstacleSensor sensor(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
ObstacleAvoidance obstacleAvoidance(&motor, &sensor);

void setup() {
    Serial.begin(9600);
}

void loop() {
    obstacleAvoidance.checkAndAvoid();
}

#include "constants.h"

// #include "motor_control.h"
// #include "obstacle_sensor.h"
// #include "obstacle_avoidance.h"

// MotorControl motor(MOTOR1_PIN1, MOTOR1_PIN2, MOTOR2_PIN1, MOTOR2_PIN2, MOTOR_SPEED_PIN1, MOTOR_SPEED_PIN2);
// ObstacleSensor sensor(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
// ObstacleAvoidance obstacleAvoidance(&motor, &sensor);

#include <huce_motor.h>

MotorControl motor(MOTOR1_PIN1, MOTOR1_PIN2, MOTOR2_PIN1, MOTOR2_PIN2, MOTOR_SPEED_PIN1, MOTOR_SPEED_PIN2)
void setup() {
    // Serial.begin(9600);
}

void loop() {
    motor.moveForward();
}

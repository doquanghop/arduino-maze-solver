#ifndef CONSTANTS_H
#define CONSTANTS_H

// Các thông số của robot
const int MOTOR1_PIN1 = 13;  // IN1 trên L298N
const int MOTOR1_PIN2 = 12;  // IN2 trên L298N
const int MOTOR2_PIN1 = 11;  // IN3 trên L298N
const int MOTOR2_PIN2 = 10;  // IN4 trên L298N

const int TRIG_PIN = 7;      // Chân Trig của cảm biến siêu âm
const int ECHO_PIN = 4;      // Chân Echo của cảm biến siêu âm
const int MAX_DISTANCE = 200; // Khoảng cách tối đa cho cảm biến siêu âm

// Các chân PWM điều khiển tốc độ của động cơ
const int MOTOR_SPEED_PIN1 = 6;  // ENA trên L298N
const int MOTOR_SPEED_PIN2 = 5;  // ENB trên L298N

#endif
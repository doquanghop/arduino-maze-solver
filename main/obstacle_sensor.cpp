#include "obstacle_sensor.h"

ObstacleSensor::ObstacleSensor(int trig, int echo, int maxDist)
    : trigPin(trig), echoPin(echo), maxDistance(maxDist), sonar(trig, echo, maxDist) {
}

int ObstacleSensor::getDistance() {
    // TODO: Đọc khoảng cách từ cảm biến siêu âm
    return sonar.ping_cm(); 
}
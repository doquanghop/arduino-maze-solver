#include "obstacle_sensor.h"

ObstacleSensor::ObstacleSensor(int trig, int echo, int maxDist) : sonar(trig, echo, maxDist) {
    this->trigPin = trig;
    this->echoPin = echo;
    this->maxDistance = maxDist;
}

int ObstacleSensor::getDistance() {
    // TODO: Đọc khoảng cách từ cảm biến siêu âm
    return sonar.ping_cm();
}
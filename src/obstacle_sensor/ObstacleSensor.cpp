#include "ObstacleSensor.h"

ObstacleSensor::ObstacleSensor(int trig, int echo, int maxDist) : sonar(trig, echo, maxDist) {
    // TODO: Khởi tạo cảm biến
}

int ObstacleSensor::getDistance() {
    // TODO: Đọc khoảng cách từ cảm biến siêu âm
    return 0;
}
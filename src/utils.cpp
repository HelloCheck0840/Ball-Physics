#include "utils.h"
#include <cmath>

std::array<float, 2> getNormal(float x1, float y1, float x2, float y2) {
    float nx = -(y2 - y1);
    float ny = x2 - x1;
    float length = std::sqrt((nx * nx) + (ny * ny));
    if (length != 0) {
        nx = nx / length;
        ny = ny / length;
    }
    return {nx, ny};
}

float dotProduct(float aX, float aY, float bX, float bY) {
    return (aX * bX) + (aY * bY);
}
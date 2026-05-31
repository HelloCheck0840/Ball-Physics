#pragma once
#include <array>
#include <cmath>

std::array<float, 2> getNormal(float x1, float y1, float x2, float y2);
float dotProduct(float aX, float aY, float bX, float bY);

struct Line {
    std::array<float, 2> pos1{};
    std::array<float, 2> pos2{};
    std::array<float, 2> normal{};

    Line(float x1, float y1, float x2, float y2) : pos1{x1, y1}, pos2{x2, y2} {
        float nx = -(y2 - y1);
        float ny = x2 - x1;
        float length = std::sqrt((nx * nx) + (ny * ny));

        if (length != 0) {
            normal[0] = nx / length;
            normal[1] = ny / length;
        } else {
            normal[0] = 0.0f;
            normal[1] = 0.0f;
        }
    }
};
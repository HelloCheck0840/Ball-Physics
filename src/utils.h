#pragma once
#include <array>

// Function declarations
std::array<float, 2> getNormal(float x1, float y1, float x2, float y2);
float dotProduct(float aX, float aY, float bX, float bY);
struct Line {
    std::array<float, 2> pos1{};
    std::array<float, 2> pos2{};

    Line(float x1, float y1, float x2, float y2) : pos1{x1, y1}, pos2{x2, y2} {}
};
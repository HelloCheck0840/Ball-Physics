#pragma once
#include <tuple>
#include "raylib.h"
#include "utils.h"
#include <vector>

class Ball {
    private:
        float x;
        float y;
        float velX;
        float velY;
        int radius;
        float gravity;
        float restitution;
        float friction;

    public:
        // Constructor
        Ball(float startX, float startY, int rad, float speed, float cor, float friction);

        // Update
        void collision(const Line& line);
        void update(const std::vector<Line>& Lines, float width, float height, float dt);

        // Draw
        void draw();

        // Setters
        float getRadius();
        std::array<float, 2> getPos();
};
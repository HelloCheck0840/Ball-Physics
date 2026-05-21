#pragma once
#include <tuple>
#include "raylib.h"
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
        void collision(float x1, float x2, float y1, float y2);
        void update(float x1, float x2, float y1, float y2, float width, float height, float dt);

        // Draw
        void draw();

        // Setters
        float getRadius();
        std::tuple<float, float> getPos();
};
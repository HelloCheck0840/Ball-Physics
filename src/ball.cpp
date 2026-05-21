#include "ball.h"
#include <tuple>
#include "raylib.h"
#include <cmath>
#include "utils.h"
#include <vector>

// Constructor
Ball::Ball(float startX, float startY, int rad, float speed, float cor, float coefficient) {
    x = startX;
    y = startY;
    gravity = 9.8f;
    velX = 0;
    velY = 0;
    radius = rad;
    restitution = cor;
    friction = coefficient;
}

void Ball::collision(float x1, float x2, float y1, float y2) {
    auto [nx, ny] = normal(x1, x2, y1, y2);

    float distanceAwayFromLine = dotProduct(x - x1, y - y1, nx, ny);

    if (distanceAwayFromLine < 0) {
        nx = -nx;
        ny = -ny;
        distanceAwayFromLine = -distanceAwayFromLine;
    }

    if (distanceAwayFromLine < radius) {
        float speedAlongNormal = dotProduct(velX, velY, nx, ny);
        float speedAlongTanget = dotProduct(velX, velY, ny, -nx);

        if (speedAlongNormal <= 0) {
            velX = -(speedAlongNormal * nx) * restitution + (speedAlongTanget * ny) * (1 - friction);
            velY = -(speedAlongNormal * ny) * restitution - (speedAlongTanget * nx) * (1 - friction);  
        }
    }
}

void Ball::update(float x1, float x2, float y1, float y2, float width, float height, float dt) {
    // Position update
    velY += gravity *  100 * dt; 
    y += velY * dt;
    x += velX * dt;

    // Reverse speed when it hits the walls
    if (x + radius >= width && velX > 0) {
        velX *= -1;
        x = width - radius;
    }
    if (x - radius <= 0 && velX < 0) {
        velX *= -1;
        x = radius;
    }
    if (y + radius >= height && velY > 0) {
        velY *= -restitution;
        y = height - radius;
    }
    if (y - radius <= 0 && velY < 0) {
        velY *= -1;
        y = radius;
    }

    // Collision Checks
    Ball::collision(x1, x2, y1, y2);    
}

// Draw
void Ball::draw() {
    DrawCircle(x, y, radius, BLACK);
}

// Setters
float Ball::getRadius() {
    return radius;
}

std::tuple<float, float> Ball::getPos() {
    return std::make_tuple(x, y);
}
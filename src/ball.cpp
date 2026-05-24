#include "ball.h"
#include <array>
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

void Ball::collision(float x1, float y1, float x2, float y2) {
    auto [nx, ny] = getNormal(x1, y1, x2, y2);

    float distanceAwayFromLine = dotProduct(x - x1, y - y1, nx, ny);

    if (distanceAwayFromLine < 0) {
        nx = -nx;
        ny = -ny;
        distanceAwayFromLine = -distanceAwayFromLine;
    }

    if (distanceAwayFromLine < radius) {
        float overlap = radius - distanceAwayFromLine;
        x += nx * overlap;
        y += ny * overlap;

        float speedAlongNormal = dotProduct(velX, velY, nx, ny);

        if (speedAlongNormal <= 0) {
            float vNormalX = speedAlongNormal * nx;
            float vNormalY = speedAlongNormal * ny;

            float vTangentX = velX - vNormalX;
            float vTangentY = velY - vNormalY;

            velX = (vTangentX * (1.0f - friction)) - (vNormalX * restitution);
            velY = (vTangentY * (1.0f - friction)) - (vNormalY * restitution);
        }
    }
}

void Ball::update(const std::vector<Line>& Lines, float width, float height, float dt) {
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
    for (const Line& line : Lines) {
        Ball::collision(line.pos1[0], line.pos1[1], line.pos2[0], line.pos2[1]);
    }
    
}

// Draw
void Ball::draw() {
    DrawCircle(x, y, radius, BLACK);
}

// Setters
float Ball::getRadius() {
    return radius;
}

std::array<float, 2> Ball::getPos() {
    return {x, y};
}
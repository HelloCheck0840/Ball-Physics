#include "raylib.h"
#include "ball.h"
#include <vector>
#include <iostream>
#include <tuple>
#include <cmath>
#include "utils.h"

struct Line {
    float pos1[2]{};
    float pos2[2]{};
};

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int radius = 15;

    SetTargetFPS(180);
    InitWindow(screenWidth, screenHeight, "Ball Physics Simulation");

    Line line;
    line.pos1[0] = 0.0f;
    line.pos1[1] = 0.0f; 
    line.pos2[0] = screenHeight;
    line.pos2[1] = screenHeight;

    const float speed = 180.0f;
    const float restitution = 1.0f;
    const float friction = 0.0f;

    Ball ball(screenHeight / 2 + 15, radius, radius, speed, restitution, friction);

    float dtCap = 0.01f;

    // Main game loop
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (dt > dtCap) {
            dt = dtCap;
        }

        ball.update(line.pos1[0], line.pos2[0], line.pos1[1], line.pos2[1], screenWidth, screenHeight, dt);
        
        // Draw
        BeginDrawing();
            ClearBackground(Color{200, 200, 255, 255});
            DrawFPS(0, 0);
            DrawLine(line.pos1[0], line.pos1[1], line.pos2[0], line.pos2[1], WHITE);
            ball.draw();
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
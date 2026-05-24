#include "raylib.h"
#include "ball.h"
#include "utils.h"
#include <vector>
#include <tuple>
#include <array>
#include <cmath>
#include <iostream>

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int radius = 15;
    float time{0};

    SetTargetFPS(180);
    InitWindow(screenWidth, screenHeight, "Ball Physics Simulation");

    // Line stuff
    std::vector<Line> Lines;
    Lines.emplace_back(0.0f, 0.0f, screenWidth / 2, screenHeight);
    Lines.emplace_back(screenWidth, 0.0f, screenWidth / 2, screenHeight);

    // Physics stuff
    const float speed = 180.0f;
    const float restitution = 0.9f;
    const float friction = 0.0f;

    Ball ball(screenWidth / 3, radius, radius, speed, restitution, friction);

    float dtCap = 0.02f;

    // Main game loop
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (dt > dtCap) {
            dt = dtCap;
        }

        // Ball update
        ball.update(Lines, screenWidth, screenHeight, dt);
        
        // Draw
        BeginDrawing();
            ClearBackground(Color{200, 200, 255, 255});
            DrawFPS(0, 0);
            for (const Line& line : Lines) {
                DrawLine(line.pos1[0], line.pos1[1], line.pos2[0], line.pos2[1], WHITE);
            }
            
            ball.draw();
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
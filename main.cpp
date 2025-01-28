#include <iostream>
#include <raylib.h>
#include "ball.hpp"
#include "paddle.hpp"

int main() {
    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 900;
    Ball ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    PlayerPaddle playerPaddle(7, SCREEN_HEIGHT / 2);
    ComputerPaddle computerPaddle (SCREEN_WIDTH - 27, SCREEN_HEIGHT / 2);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "myPong");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            ball.drawCircle();
            playerPaddle.drawPaddle();
            computerPaddle.drawPaddle();
        EndDrawing();

    }

    CloseWindow();
}
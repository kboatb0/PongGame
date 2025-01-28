#pragma once

#include <raylib.h>

class Ball{
private:
    int ballX;
    int ballY;
    int radius = 20;
public:
    Ball(int ballX, int ballY) : ballX(ballX), ballY(ballY) {}

    void drawCircle() {
        DrawCircle(ballX, ballY, radius, WHITE);
    }

};
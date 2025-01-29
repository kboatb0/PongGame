#pragma once

#include <raylib.h>

class Ball{
private:
    int ballX = 0;
    int ballY = 0;
    int radius = 20;
    int moveSpeedX = 5;
    int moveSpeedY = 4;
public:
    Ball(int ballX, int ballY) : ballX(ballX), ballY(ballY) {}

    int getBallX() {
        return ballX;
    }

    int getBallY() {
        return ballY;
    }

    int getRadius() {
        return radius;
    }

    void drawCircle() {
        DrawCircle(ballX, ballY, radius, WHITE);
    }

    void moveBall() {
        ballX += moveSpeedX;
        ballY += moveSpeedY;
        if (ballY - radius <= 0 || ballY + radius >= GetScreenHeight() ) {
            moveSpeedY *= -1;
        }else if( ballX - radius <= 0 || ballX + radius >= GetScreenWidth()) {
            moveSpeedX *= -1;
        }
    }

};
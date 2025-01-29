#pragma once

#include <raylib.h>
#include <thread>
#include <chrono>

class Ball{
private:
    int ballX = 0;
    int ballY = 0;
    int radius = 20;
    int moveSpeedX = 4;
    int moveSpeedY = 5;
public:
    Ball(int ballX, int ballY) : ballX(ballX), ballY(ballY) {} // Constructor

    // Getters for private fields
    int getBallX() const {
        return ballX;
    }

    int getBallY() const {
        return ballY;
    }

    int getRadius() const {
        return radius;
    }

    // Draw circle
    void drawCircle() {
        DrawCircle(ballX, ballY, radius, WHITE);
    }

    // Move the ball
    void moveBall() {
        ballX -= moveSpeedX;
        ballY -= moveSpeedY;
        if (ballY - radius <= 0 || ballY + radius >= GetScreenHeight()) {
            moveSpeedY *= -1;
        }
    }

    // Function that makes the ball off the paddle if it collides
    void bounce() {
        moveSpeedX *= -1;
    }

    // Reset the ball if if goes out of bound
    void resetGame() {
        if (ballX < 0 || ballX > GetScreenWidth()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            ballX = GetScreenWidth() / 2;
            ballY = GetScreenHeight() / 2;
            moveSpeedX *= -1;
        }
    }

    void displayScore(int& playerScore, int& computerScore) {
        if (ballX < 0) {
            computerScore++;
        } else if (ballX > GetScreenWidth()) {
            playerScore++;
        }
    }


};
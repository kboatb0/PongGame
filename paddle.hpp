#pragma once

#include <raylib.h>

class Paddle{
private:
    int recPosX = 0;
    int recPosY = 0;
    const int width = 20;
    const int height = 170;
    const int moveSpeed = 5;
public:

    // Getters and Setters
    void setRecPosX(int PosX) {
        recPosX = PosX;
    }

    void setRecPosY(int PosY) {
        recPosY = PosY;
    }

    int getRecPosX() const {
        return recPosX;
    }

    int getRecPosY() const {
        return recPosY;
    }

    int getWidth() const {
        return width;
    } 

    int getHeight() const {
        return height;
    }

    int getMoveSpeed() const {
        return moveSpeed;
    } 

    // Draw the paddles
    void drawPaddle() {
        Rectangle rec = {(float)getRecPosX(), (float)getRecPosY(), (float)getWidth(), (float)getHeight()};
        DrawRectangleRounded(rec, 0.8, 16, WHITE);
    }
};


class PlayerPaddle : public Paddle{
public:
    // constructor
    PlayerPaddle(int recPosX, int recPosY) {
        setRecPosX(recPosX);
        setRecPosY(recPosY - getHeight() / 2);
    }

    // Move the Player Paddle
    void movePlayerPaddle() {
        if (IsKeyDown(KEY_UP) && getRecPosY() > 0){
            setRecPosY(getRecPosY() - getMoveSpeed());
        }  
        if (IsKeyDown(KEY_DOWN) && getRecPosY() < GetScreenHeight() - getHeight()) {
            setRecPosY(getRecPosY() + getMoveSpeed());
        }
    }
};


class ComputerPaddle : public Paddle{
public:
    ComputerPaddle(int recPosX, int recPosY) {
        setRecPosX(recPosX);
        setRecPosY(recPosY - getHeight() / 2);
    }

    // Move the AI paddle
    void moveComputerPaddle(const Ball& ball) {
        if (ball.getBallY() <= getRecPosY() && getRecPosY() > 0) {
            setRecPosY(getRecPosY() - getMoveSpeed());
        } else if (ball.getBallY() >= getRecPosY() + getHeight() && getRecPosY() < GetScreenHeight() - getHeight()) {
            setRecPosY(getRecPosY() + getMoveSpeed());
        }
    }
};
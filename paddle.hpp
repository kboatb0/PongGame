#pragma once

#include <raylib.h>
// #include "ball.hpp"

class Paddle{
private:
    int recPosX = 0;
    int recPosY = 0;
    int width = 20;
    int height = 170;
    int moveSpeed = 6;
public:
    void setRecPosX(int PosX) {
        recPosX = PosX;
    }

    void setRecPosY(int PosY) {
        recPosY = PosY;
    }

    int getRecPosX() {
        return recPosX;
    }

    int getRecPosY() {
        return recPosY;
    }

    int getWidth() {
        return width;
    } 

    int getHeight() {
        return height;
    }

    int getMoveSpeed() {
        return moveSpeed;
    } 

    void drawPaddle() {
        Rectangle rec = {(float)getRecPosX(), (float)getRecPosY(), (float)getWidth(), (float)getHeight()};
        DrawRectangleRounded(rec, 0.8, 16, WHITE);
    }
};


class PlayerPaddle : public Paddle{
public:
    PlayerPaddle(int recPosX, int recPosY) {
        setRecPosX(recPosX);
        setRecPosY(recPosY - getHeight() / 2);
    }

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

    void moveComputerPaddle(Ball ball) {
        if (ball.getBallY() <= getRecPosY() + (getHeight() / 2) && getRecPosY() > 0) {
            setRecPosY(getRecPosY() - getMoveSpeed());
        } else if (ball.getBallY() >= getRecPosY() + (getHeight() / 2) && getRecPosY() < GetScreenHeight() - getHeight()) {
            setRecPosY(getRecPosY() + getMoveSpeed());
        }
    }
};
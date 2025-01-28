#pragma once

#include <raylib.h>

class Paddle{
private:
    int recPosX = 0;
    int recPosY = 0;
    int width = 20;
    int height = 170;
public:
    void setRecPosX(int PosX) {
        recPosX = PosX;
    }

    void setRecPosY(int PosY) {
        recPosY = PosY;
    }

    int getRecPosX()  {
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

    virtual void drawPaddle() = 0;
};

class PlayerPaddle : public Paddle{
public:
    PlayerPaddle(int recPosX, int recPosY) {
        setRecPosX(recPosX);
        setRecPosY(recPosY - getHeight() / 2);
    }

    void drawPaddle() override {
        Rectangle rec = {(float)getRecPosX(), (float)getRecPosY(), (float)getWidth(), (float)getHeight()};
        DrawRectangleRounded(rec, 2, 1.1, WHITE);
    }
};

class ComputerPaddle : public Paddle{
public:
    ComputerPaddle(int recPosX, int recPosY) {
        setRecPosX(recPosX);
        setRecPosY(recPosY - getHeight() / 2);
    }

    void drawPaddle() override {
        DrawRectangle(getRecPosX(), getRecPosY(), getWidth(), getHeight(), WHITE);
    }
};
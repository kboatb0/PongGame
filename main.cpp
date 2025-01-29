#include <raylib.h>
#include "ball.hpp"
#include "paddle.hpp"

int playerScore;
int computerScore;

int main() {
    // Size of the window
    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 900;

    // Objects for the headers
    Ball ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    PlayerPaddle playerPaddle(7, SCREEN_HEIGHT / 2);
    ComputerPaddle computerPaddle (SCREEN_WIDTH - 27, SCREEN_HEIGHT / 2);

    // Open the window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "myPong");
    SetTargetFPS(60);

    // Game loop
    while(!WindowShouldClose()) {

        // Cheeck collision with player paddle (Right Paddle)
        if (ball.getBallX() - ball.getRadius() <= playerPaddle.getRecPosX() + playerPaddle.getWidth() &&
            ball.getBallX() - ball.getRadius() <= playerPaddle.getRecPosX() && ball.getBallY() + ball.getRadius() >= playerPaddle.getRecPosY() 
            && ball.getBallY() - ball.getRadius() <= playerPaddle.getRecPosY() + playerPaddle.getHeight()){
                ball.bounce();
            }

        // Check collision with computer paddle (Left Paddle)
        if (ball.getBallX() >= computerPaddle.getRecPosX() - computerPaddle.getWidth() &&
            ball.getBallX() <= computerPaddle.getRecPosX() && ball.getBallY() + ball.getRadius() >= computerPaddle.getRecPosY() &&
            ball.getBallY() - ball.getRadius()  <= computerPaddle.getRecPosY() + computerPaddle.getHeight()){
                ball.bounce();
            }    

        //Update position
        ball.moveBall();
        ball.displayScore(playerScore, computerScore);
        ball.resetGame();
        playerPaddle.movePlayerPaddle();
        computerPaddle.moveComputerPaddle(ball);

        // Draw the objects
        BeginDrawing();
        ClearBackground(BLACK);
            DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
            DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 60, GRAY),
            DrawText(TextFormat("%d", playerScore), (SCREEN_WIDTH / 2) / 2, 40, 50, WHITE);
            DrawText(TextFormat("%d", computerScore), 3 *(SCREEN_WIDTH / 4), 40, 50, WHITE);
            ball.drawCircle();
            playerPaddle.drawPaddle();
            computerPaddle.drawPaddle();
        EndDrawing();

    }

    CloseWindow();
}
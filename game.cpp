#include <emscripten.h>
#include <iostream>

extern "C" {
    const int windowHeight = 800;
    const int windowWidth = 600;

    float ballX = 300.0, ballY = 400.0;
    float ballXSpeed = 5;
    float ballYSpeed = 7;

    float paddle1Y = 300.0, paddle2Y = 300.0;
    float paddle1Speed = 12.0; 
    float paddle2Speed = 8.0; 
    const float paddleWidth = 40.0;
    const float paddleHeight = 225.0;
    const float ballSize = 20;

    int paddleDirection = 0; 

    void EMSCRIPTEN_KEEPALIVE updateGame() {
        ballX += ballXSpeed;
        ballY += ballYSpeed;

        paddle2Y += paddle2Speed;

        if (ballX >= windowWidth - 20 || ballX <= 0) {
            ballXSpeed *= -1;
        }

        if (ballY >= windowHeight || ballY <= 0) {
            ballYSpeed *= -1;
        }

        if (ballY >= paddle1Y && ballY <= paddle1Y + paddleHeight && ballX <= paddleWidth) {
            ballXSpeed *= -1;
        }

        if (ballY >= paddle2Y && ballY <= paddle2Y + paddleHeight && ballX >= windowWidth - paddleWidth) {
            ballXSpeed *= -1;
        }

        if (paddle1Y <= 0) {
            paddle1Y = 0;
        }
        if (paddle1Y + paddleHeight >= windowHeight) {
            paddle1Y = windowHeight - paddleHeight;
        }

        // if (paddle2Y <= 0) {
        //     paddle2Y += paddleSpeed;
        // }
        if (paddle2Y <= 0 || paddle2Y + paddleHeight >= windowHeight) {
            paddle2Speed *= -1;
        }
    }

    void EMSCRIPTEN_KEEPALIVE movePaddle(int direction) {
        paddleDirection = direction; 
        paddle1Y += paddleDirection * paddle1Speed;
    }

    float EMSCRIPTEN_KEEPALIVE getBallX() { return ballX; }
    float EMSCRIPTEN_KEEPALIVE getBallY() { return ballY; }
    float EMSCRIPTEN_KEEPALIVE getPaddle1Y() { return paddle1Y; }
    float EMSCRIPTEN_KEEPALIVE getPaddle2Y() { return paddle2Y; }
}

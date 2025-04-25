#include <raylib.h>
#include <iostream>
#include "game.cpp"

using namespace std;

int main() {

    // Init app
    InitWindow(screenSize, screenSize, "snake game");
    SetTargetFPS(60);

    // Game setup
    Game game; 

    // Gameloop
    while (!WindowShouldClose()) {
        BeginDrawing();

        // Computing
        game.handleUserInput();
        game.snake.updateDirection(game.lastDirectionKeyPressed);
        if(game.shouldTriggerUpdate(updateInterval)) {
            bool ateFood = game.handleSnakeFoodCollition();
            
            if (ateFood) {
                game.snake.growBody();
            } else {
                game.snake.update();
            }
        }

        // Drawing
        ClearBackground(LGREEN);
        game.food.draw();
        game.snake.draw();

        EndDrawing();
    }

    // Close app
    CloseWindow();

    return 0;
}

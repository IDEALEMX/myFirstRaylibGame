#include <raylib.h>
#include <iostream>

#include "constants.cpp"
#include "food.cpp"
#include "snake.cpp"

using namespace std;

int main() {

    // Init app
    cout << "Starting the game..." << endl;
    InitWindow(screenSize, screenSize, "test");
    SetTargetFPS(60);

    // Game setup
    Food food = Food();
    Snake snake = Snake();

    // Gameloop
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(LGREEN);
        food.draw();
        snake.draw();

        EndDrawing();
    }

    // Close app
    CloseWindow();

    return 0;
}

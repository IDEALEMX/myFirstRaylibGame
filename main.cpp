#include <raylib.h>
#include <iostream>

#include "constants.cpp"
#include "food.cpp"

using namespace std;

int main() {

    // Init app
    cout << "Starting the game..." << endl;
    InitWindow(screenSize, screenSize, "test");
    SetTargetFPS(60);

    // Game setup
    Food food = Food();

    // Gameloop
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(LGREEN);
        food.draw();

        EndDrawing();
    }

    // Close app
    CloseWindow();

    return 0;
}

#include <raylib.h>
#include <iostream>

#include "constants.cpp"
#include "food.cpp"
#include "snake.cpp"

using namespace std;

// Time passed since last game update
double lastUpdateTime = 0;

bool shouldTriggerUpdate(double updateInterval) { 
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= updateInterval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

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
        
        // Computing
        if(shouldTriggerUpdate(interval)) {
            snake.update();
        }

        // Drawing
        ClearBackground(LGREEN);
        food.draw();
        snake.draw();

        EndDrawing();
    }

    // Close app
    CloseWindow();

    return 0;
}

#include <raylib.h>
#include <iostream>

#include "constants.cpp"
#include "food.cpp"
#include "snake.cpp"

using namespace std;

// Time passed since last game update
double lastUpdateTime = 0;

// Checks if a certain time interval since the last time it happened
bool shouldTriggerUpdate(double updateInterval) { 
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= updateInterval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int lastDirectionKeyPressed = KEY_RIGHT;

// Will change the last key pressed if it is a valid movement key
void handleUserInput() {
    int pressedKey = GetKeyPressed();
    if (validMovementKeys.count(pressedKey)) {
        lastDirectionKeyPressed = pressedKey;
    }
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
        
        handleUserInput();
        if(shouldTriggerUpdate(updateInterval)) {
            snake.updateDirection(lastDirectionKeyPressed);
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

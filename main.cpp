#include <raylib.h>
#include <iostream>
using namespace std;

// Game colors
const Color LGREEN = {173, 204, 96, 255};
const Color DGREEN = {43, 51, 24, 255};

// Defining grid system
const int cellSize = 30;
const int cellCount = 25;
const int screenSize = cellSize * cellCount;

int main() {

    // init app
    cout << "Starting the game..." << endl;
    InitWindow(screenSize, screenSize, "test");
    SetTargetFPS(60);

    // gameloop
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(LGREEN);

        EndDrawing();
    }

    // close app
    CloseWindow();

    return 0;
}

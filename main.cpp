#include <raylib.h>
#include <iostream>
using namespace std;

int main () {

    // init app
    cout << "Starting the game...";
    InitWindow (600, 400, "test");

    // gameloop
    while (!WindowShouldClose ()) {
        BeginDrawing ();

        ClearBackground (SKYBLUE);

        EndDrawing ();
    }

    // close app
    CloseWindow ();

    return 0;
}

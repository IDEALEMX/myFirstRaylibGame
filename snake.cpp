#include <raylib.h>
#include <deque>

#include "constants.cpp"

using namespace std;

class Snake {
public:

    // Defines default body of the snake
    deque<Vector2> body = {
        Vector2{6, 9},
        Vector2{5, 9},
        Vector2{4, 9},
    };
    Texture2D texture;

    Snake() {
        Image image = LoadImage("graphics/body.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Snake () {
        UnloadTexture(texture);
    }

    void draw() {
        for (int i = 0; i < body.size(); i++) {
            int x = body[i].x;
            int y = body[i].y;
            DrawTexture(texture, x * cellSize, y * cellSize, WHITE);
        }
    }

};

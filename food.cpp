#include <raylib.h>
#include "constants.cpp"


class Food {
public:
    Vector2 position = {4, 7};
    Texture2D texture;

    Food() {
        Image image = LoadImage("graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Food() {
        UnloadTexture(texture);
    }

    void draw() {
        /*
        DrawRectangle(
                position.x * cellSize, 
                position.y * cellSize, 
                cellSize,
                cellSize, 
                DGREEN);
        */

        DrawTexture(texture,
                    position.x * cellSize,
                    position.y * cellSize,
                    WHITE);
            
    }

};

#include <raylib.h>
#include "constants.cpp"


class Food {
public:
    Vector2 position = generateRandomPosition(); 
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
        DrawTexture(texture,
                    position.x * cellSize,
                    position.y * cellSize,
                    WHITE);
    }

    Vector2 generateRandomPosition() {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2 {x, y};
    }

};

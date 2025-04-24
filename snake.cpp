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

    Texture2D bodyTexture, faceUpTexture, faceDownTexture,
        faceRightTexture, faceLeftTexture;

    Snake() {
        // Loads images and textures of the snake's body & head
        Image bodyImage = LoadImage("graphics/body.png");
        Image faceUp = LoadImage("graphics/faceUp.png");
        Image faceDown = LoadImage("graphics/faceDown.png");
        Image faceLeft = LoadImage("graphics/faceLeft.png");
        Image faceRight = LoadImage("graphics/faceRight.png");

        bodyTexture = LoadTextureFromImage(bodyImage);
        faceUpTexture = LoadTextureFromImage(faceUp);
        faceDownTexture = LoadTextureFromImage(faceDown);
        faceLeftTexture = LoadTextureFromImage(faceLeft);
        faceRightTexture = LoadTextureFromImage(faceRight);

        UnloadImage(bodyImage);
        UnloadImage(faceUp);
        UnloadImage(faceDown);
        UnloadImage(faceLeft);
        UnloadImage(faceRight);
    }

    ~Snake () {
        UnloadTexture(bodyTexture);
        UnloadTexture(faceUpTexture);
        UnloadTexture(faceDownTexture);
        UnloadTexture(faceLeftTexture);
        UnloadTexture(faceRightTexture);
    }

    void draw() {

        /*
         * Checks the orientation of the head
         * and based on the different from the first cell (0)
         * to the next (1), chooses which texture to use
         */

        int xDifference = body[0].x - body[1].x;
        int yDifference = body[0].y - body[1].y;

        if (xDifference == 1) {
            DrawTexture(faceRightTexture, body[0].x * cellSize, body[0].y * cellSize, WHITE);
        } else if (xDifference == -1) {
            DrawTexture(faceLeftTexture, body[0].x * cellSize, body[0].y * cellSize, WHITE);
        }else if (yDifference == 1) {
            DrawTexture(faceDownTexture, body[0].x * cellSize, body[0].y * cellSize, WHITE);
        } else if (xDifference == -1) {
            DrawTexture(faceUpTexture, body[0].x * cellSize, body[0].y * cellSize, WHITE);
        }
        
        // Draws the rest of the body
        for (unsigned int i = 1; i < body.size(); i++) {
            int x = body[i].x;
            int y = body[i].y;
            DrawTexture(bodyTexture, x * cellSize, y * cellSize, WHITE);
        }
    }

};

#include <raylib.h>
#include <raymath.h>
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

    // Snake textures
    Texture2D bodyTexture, faceUpTexture, faceDownTexture,
        faceRightTexture, faceLeftTexture;

    // Direction vector
    Vector2 direction = {0, 1};

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
        } else if (yDifference == -1) {
            DrawTexture(faceUpTexture, body[0].x * cellSize, body[0].y * cellSize, WHITE);
        }
        
        // Draws the rest of the body
        for (unsigned int i = 1; i < body.size(); i++) {
            int x = body[i].x;
            int y = body[i].y;
            DrawTexture(bodyTexture, x * cellSize, y * cellSize, WHITE);
        }
    }
    
    /*
     * Updates the direction of the snake
     * supports arrowKey, wasd & vim movement
     * If a movement change actually takes place it will return true
     * else it will return false
     */

    void updateDirection(int lastKeyPressed) {
        switch(lastKeyPressed) {
            case KEY_UP: case  KEY_W: case KEY_K:
                if (direction != downVector) {
                    direction = upVector;
                }
                break;

            case KEY_DOWN: case KEY_S: case KEY_J:
                if (direction != upVector) {
                    direction = downVector;
                }
                break;

            case KEY_RIGHT: case KEY_D: case KEY_L:
                if (direction != leftVector) {
                    direction = rightVector;
                }
                break;

            case KEY_LEFT: case KEY_A: case KEY_H:
                if (direction != rightVector) {
                    direction = leftVector;
                }
                break;
        }
    }

     // Makes the snake move foward by poping the tail and adding a new head
    void update() {
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }
};

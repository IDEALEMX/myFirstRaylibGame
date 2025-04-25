#include <raylib.h>
#include <raymath.h>
#include <deque>
#include <iostream>

#include "constants.cpp"
#pragma once

#define head body[0]

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
        faceRightTexture, faceLeftTexture, deadUpTexture, deadDownTexture,
        deadRightTexture, deadLeftTexture;

    // Direction vector
    Vector2 direction = {0, 1};

    // Death related variables
    double timeOfDeath = 0;
    bool isDead = false;
    Vector2 lastPopedPart;

    Snake() {
        // Loads images and textures of the snake's body & head
        Image bodyImage = LoadImage("graphics/body.png");
        Image faceUp = LoadImage("graphics/faceUp.png");
        Image faceDown = LoadImage("graphics/faceDown.png");
        Image faceLeft = LoadImage("graphics/faceLeft.png");
        Image faceRight = LoadImage("graphics/faceRight.png");
        Image deadUp = LoadImage("graphics/deadUp.png");
        Image deadDown = LoadImage("graphics/deadDown.png");
        Image deadLeft = LoadImage("graphics/deadLeft.png");
        Image deadRight = LoadImage("graphics/deadRight.png");

        bodyTexture = LoadTextureFromImage(bodyImage);
        faceUpTexture = LoadTextureFromImage(faceUp);
        faceDownTexture = LoadTextureFromImage(faceDown);
        faceLeftTexture = LoadTextureFromImage(faceLeft);
        faceRightTexture = LoadTextureFromImage(faceRight);
        deadUpTexture = LoadTextureFromImage(deadUp);
        deadDownTexture = LoadTextureFromImage(deadDown);
        deadLeftTexture = LoadTextureFromImage(deadLeft);
        deadRightTexture = LoadTextureFromImage(deadRight);

        UnloadImage(bodyImage);
        UnloadImage(faceUp);
        UnloadImage(faceDown);
        UnloadImage(faceLeft);
        UnloadImage(faceRight);
        UnloadImage(deadUp);
        UnloadImage(deadDown);
        UnloadImage(deadLeft);
        UnloadImage(deadRight);
    }

    ~Snake () {
        UnloadTexture(bodyTexture);
        UnloadTexture(faceUpTexture);
        UnloadTexture(faceDownTexture);
        UnloadTexture(faceLeftTexture);
        UnloadTexture(faceRightTexture);
        UnloadTexture(deadUpTexture);
        UnloadTexture(deadDownTexture);
        UnloadTexture(deadLeftTexture);
        UnloadTexture(deadRightTexture);
    }

    void draw() {

        /*
         * Checks the orientation of the head
         * and based on the different from the first cell (0)
         * to the next (1), chooses which texture to use
         * if snake is dead it will show the appropiate sprite
         */

        int xDifference = head.x - body[1].x;
        int yDifference = head.y - body[1].y;

        // Chooses to which head sprite to draw
        if (isDead) {
            if (xDifference == 1) {
                DrawTexture(deadRightTexture, head.x * cellSize, head.y * cellSize, WHITE);
            } else if (xDifference == -1) {
                DrawTexture(deadLeftTexture, head.x * cellSize, head.y * cellSize, WHITE);
            }else if (yDifference == 1) {
                DrawTexture(deadDownTexture, head.x * cellSize, head.y * cellSize, WHITE);
            } else if (yDifference == -1) {
                DrawTexture(deadUpTexture, head.x * cellSize, head.y * cellSize, WHITE);
            }
        } else {
            if (xDifference == 1) {
                DrawTexture(faceRightTexture, head.x * cellSize, head.y * cellSize, WHITE);
            } else if (xDifference == -1) {
                DrawTexture(faceLeftTexture, head.x * cellSize, head.y * cellSize, WHITE);
            }else if (yDifference == 1) {
                DrawTexture(faceDownTexture, head.x * cellSize, head.y * cellSize, WHITE);
            } else if (yDifference == -1) {
                DrawTexture(faceUpTexture, head.x * cellSize, head.y * cellSize, WHITE);
            }
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
        lastPopedPart = body.back();
        body.pop_back();
        body.push_front(Vector2Add(head, direction));
    }

    // Checks if a given Vector2 position is inside the snake
    bool positionInSnake(Vector2 position, bool checkHead) {
        int start = checkHead? 0: 1;
        for (int i = start; i < body.size(); i++)  {
            if (body[i] == position) {
                return true;
            }
        }
        return false;
    }

    void growBody() {
        body.push_front(Vector2Add(head, direction));
    }
    
    /*
     * If the game detects that the snake has collided with something
     * it till set the snake as dead and revert its last movement
     * so it can be drawn as dead
     */

    void checkCollitions() {
        // check for edge or self collisions
        if (head.x < 0 || head.x > cellCount - 1 || head.y < 0 
        || head.y > cellCount - 1 || positionInSnake(head, false)) { 
            isDead = true;
            timeOfDeath = GetTime();
            body.pop_front();
            body.push_back(lastPopedPart);
        }   
    }
};

#include <raylib.h>
#include "snake.cpp"
#include "food.cpp"

#pragma once

class Game {
public:
    // Game objects
    Snake snake = Snake();
    Food food = Food();

    // Game state
    
    // Time passed since last game update
    double lastUpdateTime = 0;
    int lastDirectionKeyPressed = KEY_RIGHT;

    // handling the updating rate;
    bool shouldTriggerUpdate(double updateInterval) { 
        double currentTime = GetTime();
        if (currentTime - lastUpdateTime >= updateInterval) {
            lastUpdateTime = currentTime;
            return true;
        }
        return false;
    }

    /*
     * Update the last key pressed by the user
     * but only if the key is a valid movement key
     */

    void handleUserInput() {
        int pressedKey = GetKeyPressed();
        if (validMovementKeys.count(pressedKey)) {
            lastDirectionKeyPressed = pressedKey;
        }
    }

    /*
     * Checks if the snake is touching the food
     * if it is, it will move the good to a random location
     * if that happens it will return true
     */

    bool handleSnakeFoodCollition() {
        Vector2 newPosition;
        if(snake.body[0] == food.position) {
            do {
                newPosition = food.generateRandomPosition();
            } while (snake.positionInSnake(newPosition));
            food.position = newPosition;
            return true;
        }
        return false;
    }

};

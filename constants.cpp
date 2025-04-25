#include <raylib.h>
#include <set>

#pragma once

// Game colors
const Color LGREEN = {173, 204, 96, 255};
const Color DGREEN = {43, 51, 24, 255};

// Defining grid system
const int cellSize = 30;
const int cellCount = 25;
const int screenSize = cellSize * cellCount;

// Interval for updating the game state
const double updateInterval = 0.2;
const double movementInterval = 0.1;

// Movement vectors
const Vector2 upVector = {0, -1};
const Vector2 downVector = {0, 1};
const Vector2 rightVector = {1, 0};
const Vector2 leftVector = {-1, 0};

// Movement keys
const std::set<int> validMovementKeys = 
    {KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT,
     KEY_W, KEY_S, KEY_D, KEY_A,
     KEY_H, KEY_J, KEY_K, KEY_L};


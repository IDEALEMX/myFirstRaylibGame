#include <raylib.h>
#pragma once

// Game colors
const Color LGREEN = {173, 204, 96, 255};
const Color DGREEN = {43, 51, 24, 255};

// Defining grid system
const int cellSize = 30;
const int cellCount = 25;
const int screenSize = cellSize * cellCount;

// Interval for updating the game state
const double interval = 0.2;

// Movement vectors
const Vector2 upVector = {0, -1};
const Vector2 downVector = {0, 1};
const Vector2 rightVector = {1, 0};
const Vector2 leftVector = {-1, 0};

#include "GameEngine.h"

GameEngine::GameEngine(int width, int height) {
    screenWidth = width;
    screenHeight = height;
    window = NULL;
    renderer = NULL;
}

bool GameEngine::init() {
    return true;
}
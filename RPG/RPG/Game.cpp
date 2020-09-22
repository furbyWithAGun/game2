// Includes
#include "gameEngine.h"

// Global Constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    GameEngine engine = GameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    engine.init();
}
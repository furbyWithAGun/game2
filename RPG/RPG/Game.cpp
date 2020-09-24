// Includes
#include "RpgGameEngine.h"
#include "ZoneMap.h"

// Global Constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;

int main(int argc, char* args[])
{
    //local vars
    RpgGameEngine engine = RpgGameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    engine.init();
    engine.setUpGame();

    engine.startMainGameLoop();

    //terminate the engine
    engine.close();

    std::getchar();

    return 0;
}
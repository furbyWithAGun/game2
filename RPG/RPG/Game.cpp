// Includes
#include "RpgGameEngine.h"
#include "ZoneMap.h"

// Global Constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    //local vars
    RpgGameEngine engine = RpgGameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    //init game engine
    engine.init();

    //main game loop
    engine.startMainGameLoop();

    //terminate the engine
    engine.close();

    return 0;
}
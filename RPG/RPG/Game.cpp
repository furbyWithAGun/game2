// Includes
#include "RpgGameEngine.h"
#include "ZoneMap.h"
#include "SaveObject.h"

// Global Constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;

int main(int argc, char* args[])
{
    //local vars
    RpgGameEngine engine = RpgGameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    std::string string = "BEGIN ATTRIBUTE 1\n5\nEND ATTRIBUTE\nBEGIN ATTRIBUTE 2\n4\nEND ATTRIBUTE";
    SaveObject object = SaveObject(string);
    object.getNextAttributeString().c_str();
    object.getNextAttributeString().c_str();
    engine.init();
    engine.setUpGame();
    engine.startMainGameLoop();
    //terminate the engine
    engine.close();
    //std::getchar();
    return 0;
}
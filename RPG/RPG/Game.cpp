// Includes
#include "BaseGameEngine.h"
#include "RpgWorldBuilderScene.h"
#include "RpgGameConstants.h"

// Global Constants


int main(int argc, char* args[])
{
    //local vars
    BaseGameEngine engine = BaseGameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    engine.init();
    RpgWorldBuilderScene wbs = RpgWorldBuilderScene(&engine);
    engine.addScene(WORLD_BUILDER, &wbs);
    engine.setNextScene(WORLD_BUILDER);
    engine.startMainGameLoop();

    //terminate the engine
    engine.close();
    //std::getchar();
    return 0;
}
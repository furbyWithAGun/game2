// Includes
#include "BaseGameEngine.h"
#include "RpgWorldBuilderScene.h"
#include "RpgOverWorldScene.h"
#include "RpgGameConstants.h"

//TODO:
//attack animation
//attack functionality
//unit collision
//pathfinding
//rework user input system
//rework asset loading strategy
//make semi-not-terrible player animations ***DO IT YOU SLACKER***

int main(int argc, char* args[])
{
    //local vars
    BaseGameEngine engine = BaseGameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    engine.init();
    RpgWorldBuilderScene wbs = RpgWorldBuilderScene(&engine);
    RpgOverWorldScene ows = RpgOverWorldScene(&engine);
    engine.addScene(WORLD_BUILDER, &wbs);
    engine.addScene(OVERWORLD, &ows);
    //engine.setNextScene(WORLD_BUILDER);
    engine.setNextScene(OVERWORLD);
    engine.startMainGameLoop();

    //terminate the engine
    engine.close();
    return 0;
}
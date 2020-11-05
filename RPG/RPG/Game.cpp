// Includes
#include "BaseGameEngine.h"
#include "RpgWorldBuilderScene.h"
#include "RpgOverWorldScene.h"
#include "RpgGameConstants.h"

//TODO:
//attack animation
//move setting animations to the unit states
//move input to the units to the unit states
//make button accept call back functions
//improve attack functionality
//text feedback for combat
//display player health in menu
//enemies fight back
//pathfinding
//rework user input system
//      -- command objects
//      -- interface class    RpgKeyboardMouseInterface()
//make the game client/server
//rework asset loading strategy
//add a cleanup method to GameScene and have the engine call it when scene is over (units are a memory leak when changing scenes)
//create destructors for units (main attack is a memory leak)
//make semi-not-terrible player animations ***DO IT YOU SLACKER***
//game message system
//inventory system
//experience and leveling system

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
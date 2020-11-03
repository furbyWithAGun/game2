// Includes
#include "BaseGameEngine.h"
#include "RpgWorldBuilderScene.h"
#include "RpgOverWorldScene.h"
#include "RpgGameConstants.h"

//TODO:
//fix 'free to act/move' logic (need to add a check when changing movement bools). Unit startMovement method doesn't use freeToAct method because the logic is faulty, it would not allow movement.
//      best fix will to be to hide the movement bools behind a setter method that checks for freeToAct. then the startMovementMethod will not need to perform this check and will not be blocked. <- would only work if keys were checked everyloop
//attack animation
//make button accept call back functions
//improve attack functionality
//text feedback for combat
//display player health in menu
//enemies fight back
//pathfinding
//rework user input system
//make the game client/server
//rework asset loading strategy
//add a cleanup method to GameScene and have the engine call it when scene is over (units are a memory leak when changing scenes)
//create destructors for units (main attack is a memory leak)
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
// Includes
#include "BaseGameEngine.h"
#include "RpgWorldBuilderScene.h"
#include "RpgOverWorldScene.h"
#include "RpgGameConstants.h"

//TODO:
//create UiElement class - all UI Elements will inherit from it
// create panel UI class
// create scrollbox UI class
// create text input UI class
//rework the input rework XD. Need to have 2 layers.. One to translate SDL events into generic events, and another to translate events into commands. 
//      - layer one is specific to input type. (keyboard/mouse, gamepad, etc)
//      - layer two is specific to each scene
// have controller interface track button states (have buttonPressed be a bool attribute)
// finish Portal creation of world builder scene
// rework how scenes track and load scenes (need a map of <id, zoneMap*>)
// implement zone swiching via portals
//make button accept call back functions
//refactor worldbuilding scene menus. (Create proper classes for the menus and buttons)
//town
//basic game loop - enemy spawn / combat / loot and exp / town and healing
//pathfinding
//make "teams" to determine hostile / neutral / friendly (AI units can be on different teams, hostile to player, hostile to each other etc)
//make the game client/server
//rework asset loading strategy
//add a cleanup method to GameScene and have the engine call it when scene is over (units are a memory leak when changing scenes)
//create destructors for units (Attack pointers are a memory leak, as are the unit states)
//make semi-not-terrible player animations ***DO IT YOU SLACKER***
//game message system
//ranged combat
//inventory system
//experience and leveling system
//improve attack functionality
//attack animation
//colour code text feedback for combat
//display player health in menu

int main(int argc, char* args[])
{
    //local vars
    BaseGameEngine engine = BaseGameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    engine.init();
    RpgWorldBuilderScene wbs = RpgWorldBuilderScene(&engine);
    RpgOverWorldScene ows = RpgOverWorldScene(&engine);
    engine.addScene(WORLD_BUILDER, &wbs);
    engine.addScene(OVERWORLD, &ows);
    engine.setNextScene(WORLD_BUILDER);
    //engine.setNextScene(OVERWORLD);
    engine.startMainGameLoop();

    //terminate the engine
    engine.close();
    return 0;
}
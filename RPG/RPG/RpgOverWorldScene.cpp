#include "RpgOverWorldScene.h"
#include "Rat.h"


RpgOverWorldScene::RpgOverWorldScene() : TileGridScene()
{
    init();
}

RpgOverWorldScene::RpgOverWorldScene(BaseGameEngine* gameEngine) : TileGridScene(gameEngine)
{
    init();
}

void RpgOverWorldScene::init() {
    controllerInterface = new RpgKeysMouseController();
}

void RpgOverWorldScene::declareSceneAssets()
{
    TileGridScene::declareSceneAssets();
    //player textures
    //movement
    texturesToLoad.insert({ PLAYER_IDLE_UP_LEFT_SHEET, "images/player.png" });
    texturesToLoad.insert({ PLAYER_IDLE_UP_SHEET, "images/playerIdleUp.png" });
    texturesToLoad.insert({ PLAYER_IDLE_UP_RIGHT_SHEET, "images/player.png" });
    texturesToLoad.insert({ PLAYER_IDLE_RIGHT_SHEET, "images/playerIdleRight.png" });
    texturesToLoad.insert({ PLAYER_IDLE_DOWN_RIGHT_SHEET, "images/player.png" });
    texturesToLoad.insert({ PLAYER_IDLE_DOWN_SHEET, "images/playerIdleDown.png" });
    texturesToLoad.insert({ PLAYER_IDLE_DOWN_LEFT_SHEET, "images/player.png" });
    texturesToLoad.insert({ PLAYER_IDLE_LEFT_SHEET, "images/playerIdleLeft.png" });
    texturesToLoad.insert({ PLAYER_MOVE_DOWN_SHEET, "images/playerMoveDown.png" });
    texturesToLoad.insert({ PLAYER_MOVE_UP_SHEET, "images/playerMoveUp.png" });
    texturesToLoad.insert({ PLAYER_MOVE_RIGHT_SHEET, "images/playerMoveRight.png" });
    texturesToLoad.insert({ PLAYER_MOVE_LEFT_SHEET, "images/playerMoveLeft.png" });
    //attack
    texturesToLoad.insert({ BASIC_MELEE_ATTACK_SHEET, "images/basicMeleeAttack.png" });
    texturesToLoad.insert({ BASIC_MELEE_ATTACK_DOWN_SHEET, "images/basicMeleeAttackDown.png" });
    //enemy textures
    texturesToLoad.insert({ RAT_IDLE_DOWN, "images/rat.png" });
}

void RpgOverWorldScene::setUpScene()
{
    TileGridScene::setUpScene();

   //set background 
    backDropTileKey = WATER;

    //load scene from file
    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    firstZoneFile.loadFile();
    currentZone = ZoneMap(firstZoneFile.objects[0].rawString);

    //make units
    createUnitAtLocation(RAT, desiredTilesAcross / 2 - 3, desiredTilesDown / 2);
    createUnitAtLocation(RAT, desiredTilesAcross / 2 - 4, desiredTilesDown / 2);
    player = (Player*) createUnitAtLocation(PLAYER, desiredTilesAcross / 2, desiredTilesDown / 2);
}

void RpgOverWorldScene::handleInput()
{
    InputMessage* message = new InputMessage();
    
    controllerInterface->populateMessageQueue();
    while (controllerInterface->getNextMessage(message)) {
        switch (message->id)
        {
        case END_SCENE:
            endScene();
            break;
        case SELECT_ON:
            addCommand(InputMessage(PERFORM_MAIN_ATTACK, message->x, message->y));
            break;
        case BUTTON_2_ON:
            addCommand(InputMessage(START_MOVE_UP, message->x, message->y));
            break;
        case BUTTON_3_ON:
            addCommand(InputMessage(START_MOVE_DOWN, message->x, message->y));
            break;
        case BUTTON_4_ON:
            addCommand(InputMessage(START_MOVE_LEFT, message->x, message->y));
            break;
        case BUTTON_5_ON:
            addCommand(InputMessage(START_MOVE_RIGHT, message->x, message->y));
            break;
        case BUTTON_2_OFF:
            addCommand(InputMessage(STOP_MOVE_UP, message->x, message->y));
            break;
        case BUTTON_3_OFF:
            addCommand(InputMessage(STOP_MOVE_DOWN, message->x, message->y));
            break;
        case BUTTON_4_OFF:
            addCommand(InputMessage(STOP_MOVE_LEFT, message->x, message->y));
            break;
        case BUTTON_5_OFF:
            addCommand(InputMessage(STOP_MOVE_RIGHT, message->x, message->y));
            break;
        default:
            break;
        }
    }
    delete message;
}

void RpgOverWorldScene::sceneLogic()
{
    //call base class logic
    TileGridScene::sceneLogic();

    //handle commands
    InputMessage* message = new InputMessage();
    while (getNextCommand(message)) {
        player->handleInput(message);
    }
    delete message;
}

void RpgOverWorldScene::renderScene()
{
    TileGridScene::renderScene();
}

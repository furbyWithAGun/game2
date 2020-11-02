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
    wKeyDown = sKeyDown = dKeyDown = aKeyDown = false;
}

void RpgOverWorldScene::loadSceneAssets()
{
    TileGridScene::loadSceneAssets();
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
    SDL_Event e;
        int x, y;
        int k[2];
    
        SDL_GetMouseState(&x, &y);
        player->faceMouseDirection(x, y);
    
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            for (auto menu : menus)
            {
                if (menu.second->isActive)
                {
                    menu.second->handleEvent(&e);
                }
            }
            switch (e.type)
            {
            case SDL_QUIT:
                endScene();
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (e.button.button)
                {
                case SDL_BUTTON_LEFT:
                    player->performMainAttack();
                    break;
                default:
                    break;
                }
    
                break;
            case SDL_MOUSEBUTTONUP:
                switch (e.button.button)
                {
                case SDL_BUTTON_LEFT:
                    break;
                default:
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                case SDLK_w:
                    wKeyDown = true;
                    break;
                case SDLK_s:
                    sKeyDown = true;
                    break;
                case SDLK_a:
                    aKeyDown = true;
                    break;
                case SDLK_d:
                    dKeyDown = true;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (e.key.keysym.sym) {
                case SDLK_w:
                    wKeyDown = false;
                    break;
                case SDLK_s:
                    sKeyDown = false;
                    break;
                case SDLK_a:
                    aKeyDown = false;
                    break;
                case SDLK_d:
                    dKeyDown = false;
                    break;
                }
                break;
            default:
                break;
            }
        }
}

void RpgOverWorldScene::sceneLogic()
{
    //call base class logic
    TileGridScene::sceneLogic();

    //frames++;
    player->movingUp = wKeyDown && !sKeyDown;
    player->movingDown = sKeyDown && !wKeyDown;
    player->movingRight = dKeyDown && !aKeyDown;
    player->movingLeft = aKeyDown && !dKeyDown;
}

void RpgOverWorldScene::renderScene()
{
    TileGridScene::renderScene();
}

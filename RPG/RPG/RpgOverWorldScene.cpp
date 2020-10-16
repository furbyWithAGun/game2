#include "RpgOverWorldScene.h"
#include "Rat.h"


RpgOverWorldScene::RpgOverWorldScene() : TileGridScene()
{
    wKeyDown = sKeyDown = dKeyDown = aKeyDown = false;
}

RpgOverWorldScene::RpgOverWorldScene(BaseGameEngine* gameEngine) : TileGridScene(gameEngine)
{
    wKeyDown = sKeyDown = dKeyDown = aKeyDown = false;
}

void RpgOverWorldScene::loadSceneAssets()
{
    TileGridScene::loadSceneAssets();
    //player textures
    //movement
    texturesToLoad.insert({ PLAYER_IDLE_UP_LEFT_SHEET, "images/playerIdleUpLeft.png" });
    texturesToLoad.insert({ PLAYER_IDLE_UP_SHEET, "images/playerIdleUp.png" });
    texturesToLoad.insert({ PLAYER_IDLE_UP_RIGHT_SHEET, "images/playerIdleUpRight.png" });
    texturesToLoad.insert({ PLAYER_IDLE_RIGHT_SHEET, "images/playerIdleRight.png" });
    texturesToLoad.insert({ PLAYER_IDLE_DOWN_RIGHT_SHEET, "images/playerIdleDownRight.png" });
    texturesToLoad.insert({ PLAYER_IDLE_DOWN_SHEET, "images/playerIdleDown.png" });
    texturesToLoad.insert({ PLAYER_IDLE_DOWN_LEFT_SHEET, "images/playerIdleDownLeft.png" });
    texturesToLoad.insert({ PLAYER_IDLE_LEFT_SHEET, "images/playerIdleLeft.png" });
    texturesToLoad.insert({ PLAYER_MOVE_DOWN_SHEET, "images/playerSheet.png" });
    //attack
    texturesToLoad.insert({ BASIC_MELEE_ATTACK_SHEET, "images/basicMeleeAttack.png" });
    //enemy textures
    texturesToLoad.insert({ RAT, "images/rat.png" });
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
    player = Player(this);
    player.setStartLocation(desiredTilesAcross/ 2, desiredTilesDown/ 2);
    units.push_back(&player);
    enemy = Rat(this);
    enemy.setStartLocation(desiredTilesAcross / 2 - 3, desiredTilesDown / 2);
    units.push_back(&enemy);
    enemy2 = Rat(this);
    enemy2.setStartLocation(desiredTilesAcross / 2 - 4, desiredTilesDown / 2);
    units.push_back(&enemy2);
}

void RpgOverWorldScene::handleInput()
{
    SDL_Event e;
        int x, y;
        int k[2];
    
        SDL_GetMouseState(&x, &y);
        player.faceMouseDirection(x, y);
    
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
                    printf("%i\n", player.directionFacing);
                    player.attack();
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
    player.movingUp = wKeyDown && !sKeyDown;
    player.movingDown = sKeyDown && !wKeyDown;
    player.movingRight = dKeyDown && !aKeyDown;
    player.movingLeft = aKeyDown && !dKeyDown;
}

void RpgOverWorldScene::renderScene()
{
    TileGridScene::renderScene();
}

#include "RpgOverWorldScene.h"


RpgOverWorldScene::RpgOverWorldScene() : TileGridScene()
{
    playerMovingUp = playerMovingDown = playerMovingRight = playerMovingLeft = false;
}

RpgOverWorldScene::RpgOverWorldScene(BaseGameEngine* gameEngine) : TileGridScene(gameEngine)
{
    playerMovingUp = playerMovingDown = playerMovingRight = playerMovingLeft = false;
}

void RpgOverWorldScene::loadSceneAssets()
{
    TileGridScene::loadSceneAssets();
    texturesToLoad.insert({ PLAYER, "images/playerSheet.png" });
    texturesToLoad.insert({ 22, "images/playerSheet.png" });
    texturesToLoad.insert({ RAT, "images/rat.png" });
}

void RpgOverWorldScene::setUpScene()
{
    TileGridScene::setUpScene();

    //resize textures to match tile size
    //textures[RAT]->resize(tileHeight, tileWidth);
    //textures[PLAYER]->resize(tileHeight, tileWidth);

   //set background 
    backDropTileKey = WATER;

    //load scene from file
    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    firstZoneFile.loadFile();
    currentZone = ZoneMap(firstZoneFile.objects[0].rawString);

    //make units
    player = Player( this);
    player.addAnimation(0, 22, 2, 100);
    player.setStartLocation(desiredTilesAcross/ 2, desiredTilesDown/ 2);
    player.resize(tileWidth, tileHeight);
    player.speed = 5;
    enemy = AiUnit( this);
    enemy.addAnimation(0, RAT, 1, 10);
    enemy.setStartLocation(desiredTilesAcross / 2 - 3, desiredTilesDown / 2);
    enemy.resize(tileWidth, tileHeight);
    enemy.speed = 2;
    enemy2 = AiUnit(this);
    enemy2.addAnimation(0, RAT, 1, 10);
    enemy2.setStartLocation(desiredTilesAcross / 2 - 4, desiredTilesDown / 2);
    enemy2.resize(tileWidth, tileHeight);
    enemy2.speed = 2;
}

void RpgOverWorldScene::handleInput()
{
    SDL_Event e;
        int x, y;
        int k[2];
    
        SDL_GetMouseState(&x, &y);
    
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
                    playerMovingUp = true;
                    break;
                case SDLK_s:
                    playerMovingDown = true;
                    break;
                case SDLK_a:
                    playerMovingLeft = true;
                    break;
                case SDLK_d:
                    playerMovingRight = true;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (e.key.keysym.sym) {
                case SDLK_w:
                    playerMovingUp = false;
                    break;
                case SDLK_s:
                    playerMovingDown = false;
                    break;
                case SDLK_a:
                    playerMovingLeft = false;
                    break;
                case SDLK_d:
                    playerMovingRight = false;
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

    frames++;
    //if (playerMovingUp && !playerMovingDown && isTilePassable(player.tileLocation[0], player.tileLocation[1] - 1)) {
    if (playerMovingUp && !playerMovingDown) {
        player.startMovement(UP);
    }
    //else if (playerMovingDown && !playerMovingUp && isTilePassable(player.tileLocation[0], player.tileLocation[1] + 1)) {
    if (playerMovingDown && !playerMovingUp) {
        player.startMovement(DOWN);
    }
    //else if (playerMovingRight && !playerMovingLeft && isTilePassable(player.tileLocation[0] + 1, player.tileLocation[1])) {
    if (playerMovingRight && !playerMovingLeft) {
        player.startMovement(RIGHT);
    }
    //else if (playerMovingLeft && !playerMovingRight && isTilePassable(player.tileLocation[0] - 1, player.tileLocation[1])) {
    if (playerMovingLeft && !playerMovingRight) {
        player.startMovement(LEFT);
    }
    player.updatePlayer();
    enemy.update();
    enemy2.update();
}

void RpgOverWorldScene::renderScene()
{
    printf("tickrate: %f\n", (double) frames / SDL_GetTicks() * 1000);
    TileGridScene::renderScene();
    
    //draw player
    player.draw();

    //draw other units
    enemy.draw();
    enemy2.draw();
    //draw menus
    for (auto menu : menus)
    {
        if (menu.second->isActive)
        {
            menu.second->draw();
        }
    }
}

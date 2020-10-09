#include "RpgOverWorldScene.h"

RpgOverWorldScene::RpgOverWorldScene() : TileGridScene()
{
}

RpgOverWorldScene::RpgOverWorldScene(BaseGameEngine* gameEngine) : TileGridScene(gameEngine)
{
}

void RpgOverWorldScene::loadSceneAssets()
{
    TileGridScene::loadSceneAssets();
    texturesToLoad.insert({ PLAYER, "images/player.png" });
}

void RpgOverWorldScene::setUpScene()
{
    //resize player texture to match tile size
    //textures[PLAYER].resize(tileHeight, tileWidth);
    //player = Player(&textures[PLAYER], this);
    //int screenCoords[2];
    //coordsFromTileIndex(DESIRED_TILES_ACROSS / 2, DESIRED_TILES_DOWN / 2, screenCoords);
    //playerScreenX = screenCoords[0];
    //playerScreenY = screenCoords[1];
    //player.setStartLocation(DESIRED_TILES_ACROSS / 2, DESIRED_TILES_DOWN / 2);
}

bool RpgOverWorldScene::handleInput()
{
    return false;
}

bool RpgOverWorldScene::sceneLogic()
{
    return false;
}

bool RpgOverWorldScene::renderScene()
{
    return false;
}

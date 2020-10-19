#include "TileGridScene.h"
#include "BaseGameEngine.h"
#include "Unit.h"
#include "Player.h"
#include "Rat.h"

//constants
const double LEFT_MENU_SIZE = 0.1;
const int DEFAULT_DESIRED_TILES_DOWN = 10;
const int DEFAULT_DESIRED_TILES_ACROSS = 19;

//constructors
TileGridScene::TileGridScene() : GameScene() {
    tileHeight = 50;
    tileWidth = 50;
    xOffset = 0;
    yOffset = 0;
    mainCanvasStartX = 0;
    backDropTileKey = WATER;
    desiredTilesAcross = DEFAULT_DESIRED_TILES_ACROSS;
    desiredTilesDown = DEFAULT_DESIRED_TILES_DOWN;
}

TileGridScene::TileGridScene(BaseGameEngine* gameEngine) : GameScene((BaseGameEngine*) gameEngine) {
    tileHeight = 50;
    tileWidth = 50;
    xOffset = 0;
    yOffset = 0;
    mainCanvasStartX = engine->screenWidth * LEFT_MENU_SIZE + 1;
    backDropTileKey = WATER;
    desiredTilesAcross = DEFAULT_DESIRED_TILES_ACROSS;
    desiredTilesDown = DEFAULT_DESIRED_TILES_DOWN;
}

void TileGridScene::loadSceneAssets()
{
    texturesToLoad.insert({ WATER, "images/water.png" });
    texturesToLoad.insert({ TREE, "images/tree.png" });
    texturesToLoad.insert({ GRASS, "images/grass.png" });
    texturesToLoad.insert({ MOUNTAIN, "images/mountain.png" });
}

void TileGridScene::setUpScene()
{
    createTiles();
}

void TileGridScene::handleInput()
{

}

void TileGridScene::sceneLogic()
{
    for (auto unit : units) {
        if (unit->active)
        {
            unit->update();
        }
    }
}

void TileGridScene::renderScene()
{
    //fill screen with backdrop
    for (size_t i = 0; i * tileHeight <= engine->screenHeight + tileHeight; i++)
    {
        for (size_t j = 0; j * tileWidth <= engine->screenWidth + tileWidth; j++) {
            engine->renderTexture(textures[backDropTileKey], ((tileWidth * j) + mainCanvasStartX) + (xOffset % tileWidth) - tileWidth, tileHeight * i + (yOffset % tileHeight) - tileHeight, tileWidth, tileHeight);
        }
    }

    //draw zone
    for (int i = 0; i < currentZone.tileMap.size(); i++) {
        for (int j = 0; j < currentZone.tileMap[i].size(); j++) {
            engine->renderTexture(textures[mapTiles[currentZone.tileMap[i][j]].textureKey], (tileWidth * j) + mainCanvasStartX + xOffset, tileHeight * i + yOffset, tileWidth, tileHeight);
        }
    }

    //draw units
    for (auto unit : units) {
        if (unit->active)
        {
            unit->draw();
        }
    }
    
    //cover Left side
    SDL_Rect fillRect = { 0, 0, mainCanvasStartX, engine->screenHeight };
    SDL_SetRenderDrawColor(engine->getMainRenderer(), 0, 0, 0, 0);
    SDL_RenderFillRect(engine->getMainRenderer(), &fillRect);

    //draw menus
    for (auto menu : menus)
    {
        if (menu.second->isActive)
        {
            menu.second->draw();
        }
    }
}

void TileGridScene::coordsFromTileIndex(int x, int y, int returnCoords[2]) {
    returnCoords[0] = x * tileWidth + mainCanvasStartX + xOffset;
    returnCoords[1] = y * tileHeight + yOffset;
}

//protected methods
void TileGridScene::getTileIndexFromScreenCoords(int x, int y, int tileIndices[2]) {
    tileIndices[0] = floor(((x - xOffset - mainCanvasStartX)) / tileWidth);
    tileIndices[1] = floor((y - yOffset) / tileHeight);
}


bool TileGridScene::coordsAreOnDisplayedMapTile(int x, int y) {
    int k[2];
    getTileIndexFromScreenCoords(x, y, k);
    return ((mainCanvasStartX <= x) && (k[0] >= 0) && (k[0] < currentZone.tileMap[0].size()) && (k[1] >= 0) && (k[1] < currentZone.tileMap.size()));
}

Unit* TileGridScene::getUnitAtLocation(int x, int y)
{
    for (auto unit : units )
    {
        if ( unit->active && ((unit->tileLocation[0] == x && unit->tileLocation[1] == y) || unit->tileDestination[0] == x && unit->tileDestination[1] == y)) {
            return unit;
        }
    }
    return nullptr;
}

void TileGridScene::createUnitAtLocation(int unitType, int x, int y)
{
    switch (unitType)
    {
    case PLAYER:
        units.push_back(new Player(this, x, y));
        break;
    case RAT:
        units.push_back(new Rat(this, x, y));
    default:
        break;
    }
}

bool TileGridScene::isTilePassable(int x, int y) {
    if (x < 0 || y < 0 || y >= currentZone.tileMap.size() || x >= currentZone.tileMap[y].size())
    {
        return false;
    }
    return mapTiles[currentZone.tileMap[y][x]].passable && getUnitAtLocation(x, y) == NULL;
}

//private methods
void TileGridScene::createTiles() {
    //create the different tiles
    mapTiles[GRASS] = MapTile(true, GRASS);
    mapTiles[TREE] = MapTile(false, TREE);
    mapTiles[WATER] = MapTile(false, WATER);
    mapTiles[MOUNTAIN] = MapTile(false, MOUNTAIN);


    //resize tiles depending on screen size
    int tilesImpliedWidth = engine->screenWidth / desiredTilesAcross;
    int tilesImpliedHeight = engine->screenHeight / desiredTilesDown;
    if (tilesImpliedHeight >= tilesImpliedWidth) {
        tileHeight = tilesImpliedHeight;
        tileWidth = tilesImpliedHeight;
    }
    else {
        tileHeight = tilesImpliedWidth;
        tileWidth = tilesImpliedWidth;
    }
}
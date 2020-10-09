#include "TileGridScene.h"
#include "BaseGameEngine.h"

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
    backDropTileKey = 0;
    desiredTilesAcross = DEFAULT_DESIRED_TILES_ACROSS;
    desiredTilesDown = DEFAULT_DESIRED_TILES_DOWN;
}

TileGridScene::TileGridScene(BaseGameEngine* gameEngine) : GameScene((BaseGameEngine*) gameEngine) {
    tileHeight = 50;
    tileWidth = 50;
    xOffset = 0;
    yOffset = 0;
    mainCanvasStartX = engine->screenWidth * LEFT_MENU_SIZE + 1;
    backDropTileKey = 0;
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

bool TileGridScene::handleInput()
{
    return true;
}

bool TileGridScene::sceneLogic()
{
    return true;
}

bool TileGridScene::renderScene()
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
    return true;
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

bool TileGridScene::isTilePassable(int x, int y) {
    if (x < 0 || y < 0 || y >= currentZone.tileMap.size() || x >= currentZone.tileMap[y].size())
    {
        return false;
    }
    return mapTiles[currentZone.tileMap[y][x]].passable;
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

    //for (auto i = mapTiles.begin(); i != mapTiles.end(); i++) {
        //engine->textures[i->second.textureKey].resize(tileHeight, tileWidth);
    //}
}
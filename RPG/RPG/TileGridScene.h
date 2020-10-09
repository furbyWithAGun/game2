#pragma once
#include "GameScene.h"
#include "MapTile.h"
#include "ZoneMap.h"

enum TEXTURE_NAMES
{
    GRASS,
    TREE,
    WATER,
    MOUNTAIN,
    BUTTON_BACKGROUND,
    PLAYER,
    NUM_TEXTURES
};

class BaseGameEngine;

class TileGridScene : public GameScene
{
public:
    //constructor
    TileGridScene();
    TileGridScene(BaseGameEngine* gameEngine);

    //methods
    void loadSceneAssets();
    void setUpScene();
    void handleInput();
    void sceneLogic();
    void renderScene();

protected:
    //attributes
    std::unordered_map<int, MapTile> mapTiles;
    int tileHeight;
    int tileWidth;
    ZoneMap currentZone;
    int xOffset, yOffset;
    int mainCanvasStartX;
    int backDropTileKey;
    int desiredTilesAcross;
    int desiredTilesDown;

    //methods
    void getTileIndexFromScreenCoords(int x, int y, int tileIndices[2]);
    void coordsFromTileIndex(int x, int y, int returnCoords[2]);
    bool coordsAreOnDisplayedMapTile(int x, int y);
    bool isTilePassable(int x, int y);

private:
    //attributes

    //methods
    void createTiles();
};


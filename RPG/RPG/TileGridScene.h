#pragma once
#include "GameScene.h"
#include "MapTile.h"
#include "ZoneMap.h"
#include "GameMenu.h"
#include "RpgGameConstants.h"

class BaseGameEngine;

class TileGridScene : public GameScene
{
public:
    //attributes
    ZoneMap currentZone;
    std::unordered_map<int, MapTile> mapTiles;

    //constructor
    TileGridScene();
    TileGridScene(BaseGameEngine* gameEngine);

    //methods
    void coordsFromTileIndex(int x, int y, int returnCoords[2]);
    virtual void loadSceneAssets() override;
    virtual void setUpScene() override;
    bool handleInput() override;
    bool sceneLogic() override;
    bool renderScene() override;

protected:
    //attributes
    int tileHeight;
    int tileWidth;
    int xOffset, yOffset;
    int mainCanvasStartX;
    int backDropTileKey;
    int desiredTilesAcross;
    int desiredTilesDown;
    std::unordered_map<int, GameMenu*> menus;

    //methods
    void getTileIndexFromScreenCoords(int x, int y, int tileIndices[2]);
    bool coordsAreOnDisplayedMapTile(int x, int y);
    bool isTilePassable(int x, int y);

private:
    //attributes

    //methods
    void createTiles();
};


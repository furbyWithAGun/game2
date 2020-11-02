#pragma once
#include "GameScene.h"
#include "MapTile.h"
#include "ZoneMap.h"
#include "GameMenu.h"
#include "RpgGameConstants.h"


class BaseGameEngine;
class Unit;

class TileGridScene : public GameScene
{
public:
    //attributes
    int xOffset, yOffset;
    ZoneMap currentZone;
    std::unordered_map<int, MapTile> mapTiles;
    int tileHeight;
    int tileWidth;

    //constructor
    TileGridScene();
    TileGridScene(BaseGameEngine* gameEngine);

    //methods
    void coordsFromTileIndex(int x, int y, int returnCoords[2]);
    virtual void loadSceneAssets() override;
    virtual void setUpScene() override;
    void handleInput() override;
    void sceneLogic() override;
    void renderScene() override;
    Unit* getUnitAtLocation(int x, int y);
    bool isTilePassable(int x, int y);
    

protected:
    //attributes
    int mainCanvasStartX;
    int backDropTileKey;
    int desiredTilesAcross;
    int desiredTilesDown;
    std::unordered_map<int, GameMenu *> menus;
    std::vector<Unit *> units;

    //methods
    void getTileIndexFromScreenCoords(int x, int y, int tileIndices[2]);
    bool coordsAreOnDisplayedMapTile(int x, int y);
    Unit* createUnitAtLocation(int unitType, int x, int y);
    

private:
    //attributes

    //methods
    void createTiles();
    void init();
};


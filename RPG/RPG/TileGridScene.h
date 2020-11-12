#pragma once
#include "GameScene.h"
#include "MapTile.h"
#include "ZoneMap.h"
#include "GameMenu.h"
#include "RpgGameConstants.h"
#include "CombatText.h"


class BaseGameEngine;
class Unit;
class Player;

class TileGridScene : public GameScene
{
public:
    //attributes
    int mainCanvasStartX;
    int xOffset, yOffset;
    ZoneMap currentZone;
    std::unordered_map<int, MapTile> mapTiles;
    std::vector<int> zonePortalImages;
    int tileHeight;
    int tileWidth;
    Player* player;

    //constructor
    TileGridScene();
    TileGridScene(BaseGameEngine* gameEngine);

    //methods
    void coordsFromTileIndex(int x, int y, int returnCoords[2]);
    virtual void declareSceneAssets() override;
    virtual void setUpScene() override;
    void handleInput() override;
    void sceneLogic() override;
    void renderScene() override;
    Unit* getUnitAtLocation(int x, int y);
    bool isTilePassable(int x, int y);
    void addCombatMessage(std::string text, int tileX, int tileY);
    void addCombatMessage(std::string text, int tileX, int tileY, int duration);
    void addCombatMessage(std::string text, SDL_Color colour, int tileX, int tileY);
    void addCombatMessage(std::string text, SDL_Color colour, int tileX, int tileY, int duration);
    

protected:
    //attributes
    int backDropTileKey;
    int desiredTilesAcross;
    int desiredTilesDown;
    std::vector<Unit *> units;

    //methods
    void getTileIndexFromScreenCoords(int x, int y, int tileIndices[2]);
    bool coordsAreOnDisplayedMapTile(int x, int y);
    Unit* createUnitAtLocation(int unitType, int x, int y);
    

private:
    //attributes
    std::vector<CombatText> combatMessages;

    //methods
    void createTiles();
    void init();
    void drawCombatMessages();
    void updateCombatMessages();
};


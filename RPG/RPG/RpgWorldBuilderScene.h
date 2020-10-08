#pragma once
#include "GameScene.h"
#include "MapTile.h"
#include <unordered_map>
#include "Player.h"
#include "GameMenu.h"
#include "ZoneMap.h"

class RpgGameEngine;

class RpgWorldBuilderScene : public GameScene
{
public:
    //attributes
    RpgGameEngine* engine;

    //std::unordered_map<int, MapTile> mapTiles;

    //constructor
    RpgWorldBuilderScene();
    RpgWorldBuilderScene(RpgGameEngine* gameEngine);

    //methods
    void loadSceneAssets();
    void setUpScene();
    void handleInput();
    void sceneLogic();
    void renderScene();

private:
    //attributes
    std::unordered_map<int, MapTile> mapTiles;
    std::unordered_map<int, GameMenu*> menus;
    ZoneMap currentZone;
    int tileHeight;
    int tileWidth;
    int playerScreenX, playerScreenY;
    Player player;
    bool placingTile;
    MapTile* tileBeingPlaced;
    int xOffset, yOffset;
    //methods
    void createTiles();
};


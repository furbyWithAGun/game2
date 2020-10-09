#pragma once
#include "TileGridScene.h"
#include "MapTile.h"
#include <unordered_map>
#include "Player.h"
#include "GameMenu.h"
#include "ZoneMap.h"

class RpgGameEngine;

class RpgWorldBuilderScene : public TileGridScene
{
public:
    //attributes
    RpgGameEngine* engine;

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
    std::unordered_map<int, GameMenu*> menus;
    bool placingTile;
    MapTile* tileBeingPlaced;
    bool leftButtonClicked;

    //methods
};


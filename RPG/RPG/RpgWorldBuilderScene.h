#pragma once
#include "TileGridScene.h"
#include "MapTile.h"
#include <unordered_map>
#include "Player.h"
#include "GameMenu.h"
#include "ZoneMap.h"
#include "RpgGameConstants.h"

class BaseGameEngine;

class RpgWorldBuilderScene : public TileGridScene
{
public:
    //attributes
    BaseGameEngine* engine;
    bool placingTile;
    bool leftButtonClicked;
    MapTile* tileBeingPlaced;

    //constructor
    RpgWorldBuilderScene();
    RpgWorldBuilderScene(BaseGameEngine* gameEngine);

    //methods
    void declareSceneAssets();
    void setUpScene() override;
    void handleInput() override;
    void sceneLogic() override;
    void renderScene() override;

private:
    //attributes

    //methods
    void init();
};


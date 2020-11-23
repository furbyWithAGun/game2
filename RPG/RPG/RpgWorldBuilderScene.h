#pragma once
#include "TileGridScene.h"
#include "MapTile.h"
#include <unordered_map>
#include "Player.h"
#include "GameMenu.h"
#include "ZoneMap.h"
#include "RpgGameConstants.h"
#include "RpgKeysMouseController.h"

class BaseGameEngine;

class RpgWorldBuilderScene : public TileGridScene
{
public:
    //attributes
    BaseGameEngine* engine;
    bool placingTile;
    MapTile* tileBeingPlaced;
    bool placingPortal;
    int portalBeingPlaced;
    int portalBeingPlacedExitId;
    int portalBeingPlacedExitCoordsX;
    int portalBeingPlacedExitCoordsY;

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
    void scrollCamera();
};


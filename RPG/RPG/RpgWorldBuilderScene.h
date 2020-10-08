#pragma once
#include "GameScene.h"
#include "MapTile.h"
#include <unordered_map>

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
    int tileHeight;
    int tileWidth;

    //methods
    void createTiles();
};


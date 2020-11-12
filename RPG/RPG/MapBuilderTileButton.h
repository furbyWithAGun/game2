#pragma once
#include "MenuButton.h"
#include "RpgWorldBuilderScene.h"
#include "BaseGameEngine.h"

class MapBuilderTileButton : public MenuButton
{
public:
    //attributes
    RpgWorldBuilderScene* scene;
    BaseGameEngine* engine;
    MapTile* tile;

    //constructors
    MapBuilderTileButton();
    MapBuilderTileButton(MapTile* newTile, RpgWorldBuilderScene* gameScene);

    //methods
    void onClick();
};


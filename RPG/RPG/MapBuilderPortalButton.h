#pragma once
#include "MenuButton.h"
#include "RpgWorldBuilderScene.h"
#include "BaseGameEngine.h"

class MapBuilderPortalButton : public MenuButton
{
public:
    //attributes
    RpgWorldBuilderScene* scene;
    int portalKey;

    //constructors
    MapBuilderPortalButton();
    MapBuilderPortalButton(int newPortalKey, RpgWorldBuilderScene* gameScene);

    //methods
    void onClick();
};


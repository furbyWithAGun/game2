#pragma once
#include "GameMenu.h"
#include "MapBuilderTileButton.h"
#include "MapBuilderPortalButton.h"
#include "SaveMapBuilderButton.h"
#include "MenuText.h"
#include "ScrollBox.h"

class ZoneBuilderMenu : public GameMenu
{
public:
    //constructors
    ZoneBuilderMenu();
    ZoneBuilderMenu(RpgWorldBuilderScene* gameScene, int newId, int newWidth, int newHeight, int newXPos, int newYPos);

    //methods
    bool handleInput(InputMessage* message);

private:
    //attributes
    BaseGameEngine* engine;
    RpgWorldBuilderScene* scene;

    //methods
    void buildButtons();
};


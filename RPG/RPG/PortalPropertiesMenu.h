#pragma once
#include "MenuText.h"
#include "ScrollBox.h"
#include "TextBox.h"
#include "GameMenu.h"
#include "PortalPropertiesOkButton.h"

class RpgWorldBuilderScene;

class PortalPropertiesMenu : public GameMenu
{
public:
    //constructors
    PortalPropertiesMenu();
    PortalPropertiesMenu(RpgWorldBuilderScene* gameScene, int newId, int newWidth, int newHeight, int newXPos, int newYPos);

    //methods
    bool handleInput(InputMessage* message);
    void setPortalBeingBuiltProperties();
    void open() override;

private:
    //attributes
    RpgWorldBuilderScene* scene;

    //methods
    void buildElements();
};


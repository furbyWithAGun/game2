#pragma once
#include "MenuButton.h"
//#include "RpgWorldBuilderScene.h"
#include "BaseGameEngine.h"

class PortalPropertiesMenu;

class PortalPropertiesOkButton : public MenuButton
{
public:
    //attributes
    //RpgWorldBuilderScene* scene;
    PortalPropertiesMenu* menu;

    //constructors
    PortalPropertiesOkButton();
    PortalPropertiesOkButton(PortalPropertiesMenu* newMenu);

    //methods
    void onClick() override;
};


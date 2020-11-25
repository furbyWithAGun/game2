#pragma once
#include "MenuButton.h"
#include "BaseGameEngine.h"

class PortalPropertiesMenu;

class PortalPropertiesOkButton : public MenuButton
{
public:
    //attributes
    PortalPropertiesMenu* menu;

    //constructors
    PortalPropertiesOkButton();
    PortalPropertiesOkButton(PortalPropertiesMenu* newMenu, int xpos, int ypos);

    //methods
    void onClick() override;
};


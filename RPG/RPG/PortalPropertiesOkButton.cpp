#include "PortalPropertiesOkButton.h"
#include "PortalPropertiesMenu.h"

PortalPropertiesOkButton::PortalPropertiesOkButton() : MenuButton()
{
    scene = NULL;
}

//PortalPropertiesOkButton::PortalPropertiesOkButton(PortalPropertiesMenu* newMenu, int xpos, int ypos) : MenuButton(newMenu->scene, BUTTON_BACKGROUND)
PortalPropertiesOkButton::PortalPropertiesOkButton(PortalPropertiesMenu* newMenu, int xpos, int ypos) : MenuButton()
{
    menu = newMenu;
}

void PortalPropertiesOkButton::onClick()
{
    menu->setPortalBeingBuiltProperties();
    menu->close();
}

#include "PortalPropertiesMenu.h"

PortalPropertiesMenu::PortalPropertiesMenu() : GameMenu()
{
    scene = NULL;
}

PortalPropertiesMenu::PortalPropertiesMenu(RpgWorldBuilderScene* gameScene, int newId, int newWidth, int newHeight, int newXPos, int newYPos) : GameMenu(gameScene->engine, newId, newWidth, newHeight, newXPos, newYPos)
{
    scene = gameScene;
    buildElements();
}

bool PortalPropertiesMenu::handleInput(InputMessage* message)
{
    bool messageConsumed = false;
    if (GameMenu::handleInput(message))
    {
        messageConsumed = true;
    }
    return messageConsumed;
}

void PortalPropertiesMenu::buildElements()
{
    addElement(new MenuText(scene, "Portal Properties", { 255, 255, 255 }, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.01));
    addElement(new MenuText(scene, "Exit Zone ID", { 255, 255, 255 }, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.05));
    addElement(new TextBox(scene, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.09, engine->screenWidth * 0.02, engine->screenWidth * 0.02));
    addElement(new MenuText(scene, "Exit Zone Coords", { 255, 255, 255 }, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.13));
    addElement(new TextBox(scene, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.17, engine->screenWidth * 0.02, engine->screenWidth * 0.02));
    addElement(new TextBox(scene, xpos + engine->screenWidth * 0.04, ypos + engine->screenHeight * 0.17, engine->screenWidth * 0.02, engine->screenWidth * 0.02));
}

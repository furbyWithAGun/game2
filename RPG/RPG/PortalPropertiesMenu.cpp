#include "PortalPropertiesMenu.h"
#include "RpgWorldBuilderScene.h"

enum PORTAL_PROPERTIES_MENU_IDS  {
    PORTAL_PROPERTIES_LABEL,
    EXIT_ZONE_ID_LABEL,
    EXIT_ZONE_COORDS_LABEL,
    EXIT_ZONE_ID_TEXT,
    EXIT_COORDS_X_TEXT,
    EXIT_COORDS_Y_TEXT,
    PORTAL_PROPERTIES_OK_BUTTON,
    PORTAL_PROPERTIES_CANCEL_BUTTON
};

PortalPropertiesMenu::PortalPropertiesMenu() : GameMenu()
{
    scene = NULL;
}

PortalPropertiesMenu::PortalPropertiesMenu(RpgWorldBuilderScene* gameScene, int newId, int newWidth, int newHeight, int newXPos, int newYPos) : GameMenu(gameScene->engine, newId, newWidth, newHeight, newXPos, newYPos)
{
    scene = gameScene;
    buildElements();
}

void PortalPropertiesMenu::open() {
    getElementbyId(EXIT_ZONE_ID_TEXT)->setText(std::to_string(scene->portalBeingPlacedExitId));
    getElementbyId(EXIT_COORDS_X_TEXT)->setText(std::to_string(scene->portalBeingPlacedExitCoordsX));
    getElementbyId(EXIT_COORDS_Y_TEXT)->setText(std::to_string(scene->portalBeingPlacedExitCoordsY));
    isActive = true;
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

void PortalPropertiesMenu::setPortalBeingBuiltProperties()
{
    scene->portalBeingPlacedExitId = stoi(getElementbyId(EXIT_ZONE_ID_TEXT)->getText());
    scene->portalBeingPlacedExitCoordsX = stoi(getElementbyId(EXIT_COORDS_X_TEXT)->getText());
    scene->portalBeingPlacedExitCoordsY = stoi(getElementbyId(EXIT_COORDS_Y_TEXT)->getText());
}

void PortalPropertiesMenu::buildElements()
{
    addElement(PORTAL_PROPERTIES_LABEL, new MenuText(scene, "Portal Properties", { 255, 255, 255 }, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.01));
    addElement(EXIT_ZONE_ID_LABEL, new MenuText(scene, "Exit Zone ID", { 255, 255, 255 }, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.05));
    addElement(EXIT_ZONE_ID_TEXT, new TextBox(scene, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.09, engine->screenWidth * 0.02, engine->screenWidth * 0.02));
    addElement(EXIT_ZONE_COORDS_LABEL, new MenuText(scene, "Exit Zone Coords", { 255, 255, 255 }, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.13));
    addElement(EXIT_COORDS_X_TEXT, new TextBox(scene, xpos + engine->screenWidth * 0.01, ypos + engine->screenHeight * 0.17, engine->screenWidth * 0.02, engine->screenWidth * 0.02));
    addElement(EXIT_COORDS_Y_TEXT, new TextBox(scene, xpos + engine->screenWidth * 0.04, ypos + engine->screenHeight * 0.17, engine->screenWidth * 0.02, engine->screenWidth * 0.02));
    //addElement(PORTAL_PROPERTIES_OK_BUTTON, new PortalPropertiesOkButton(this));
}

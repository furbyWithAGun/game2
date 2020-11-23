#include "MapBuilderPortalButton.h"

//constants
static const int WIDTH_ADJUSTOR = 38;
static const int HEIGHT_ADJUSTOR = 20;

//constructors
MapBuilderPortalButton::MapBuilderPortalButton() : MenuButton() {
    portalKey = -1;
    scene = NULL;
}

MapBuilderPortalButton::MapBuilderPortalButton(int newPortalKey, RpgWorldBuilderScene* gameScene) : MenuButton(newPortalKey, gameScene) {
    scene = gameScene;
    portalKey = newPortalKey;
    width = scene->engine->screenWidth / WIDTH_ADJUSTOR;
    height = scene->engine->screenHeight / HEIGHT_ADJUSTOR;
}

//methods
void MapBuilderPortalButton::onClick() {
    scene->openMenu(PORTAL_PROPERTIES_MENU);
    scene->placingTile = false;
    scene->placingPortal = true;
    scene->portalBeingPlaced = portalKey;
}

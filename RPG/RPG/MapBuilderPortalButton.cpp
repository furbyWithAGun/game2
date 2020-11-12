#include "MapBuilderPortalButton.h"

//constants
static const int WIDTH_ADJUSTOR = 38;
static const int HEIGHT_ADJUSTOR = 20;

//constructors
MapBuilderPortalButton::MapBuilderPortalButton() : MenuButton() {
    engine = NULL;
    portalKey = -1;
    scene = NULL;
}

MapBuilderPortalButton::MapBuilderPortalButton(int newPortalKey, RpgWorldBuilderScene* gameScene) : MenuButton(newPortalKey, gameScene) {
    scene = gameScene;
    engine = gameScene->engine;
    portalKey = newPortalKey;
    width = engine->screenWidth / WIDTH_ADJUSTOR;
    height = engine->screenHeight / HEIGHT_ADJUSTOR;
}

//methods
void MapBuilderPortalButton::onClick() {
    scene->placingTile = false;
    scene->placingPortal = true;
    scene->portalBeingPlaced = portalKey;
}

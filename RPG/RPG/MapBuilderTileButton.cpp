#include "MapBuilderTileButton.h"

//constants
static const int WIDTH_ADJUSTOR = 38;
static const int HEIGHT_ADJUSTOR = 20;

//constructors
MapBuilderTileButton::MapBuilderTileButton() : MenuButton() {
    engine = NULL;
    tile = NULL;
    scene = NULL;
}

MapBuilderTileButton::MapBuilderTileButton(MapTile* newTile, RpgWorldBuilderScene* gameScene) : MenuButton(newTile->textureKey, gameScene) {
    scene = gameScene;
    engine = gameScene->engine;
    tile = newTile;
    width = engine->screenWidth / WIDTH_ADJUSTOR;
    height = engine->screenHeight / HEIGHT_ADJUSTOR;
}

//methods
void MapBuilderTileButton::onClick() {
    scene->placingTile = true;
    scene->placingPortal = false;
    scene->tileBeingPlaced = tile;
}

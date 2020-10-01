#pragma once
#include "RpgGameEngine.h"

class MapBuilderTileButton : public MenuButton {
    public:
        //constants
        static const int WIDTH_ADJUSTOR = 38;
        static const int HEIGHT_ADJUSTOR = 20;
        //attributes
        RpgGameEngine* engine;
        MapTile* tile;

        //constructors
        MapBuilderTileButton() : MenuButton() {
            engine = NULL;
            tile = NULL;
        }

        MapBuilderTileButton(MapTile* newTile, RpgGameEngine* gameEngine) : MenuButton(gameEngine->textures[newTile->textureKey], (BaseGameEngine*) gameEngine) {
            engine = gameEngine;
            tile = newTile;
            width = engine->screenWidth / WIDTH_ADJUSTOR;
            height = engine->screenHeight / HEIGHT_ADJUSTOR;
        }

        //destructor
        //~MapBuilderTileButton() {

        //}

        //methods
        void onClick() {
            engine->placingTile = true;
            engine->tileBeingPlaced = tile;
        }
};
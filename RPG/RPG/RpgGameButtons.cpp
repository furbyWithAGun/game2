#pragma once
#include "RpgGameEngine.h"

class MapBuilderTileButton : public MenuButton {
    public:
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
        }

        //destructor
        //~MapBuilderTileButton() {

        //}

        //methods
        void onClick() {
            printf("clicked");
        }
};
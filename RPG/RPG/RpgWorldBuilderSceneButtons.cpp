#pragma once
#include "RpgWorldBuilderScene.h"
#include "BaseGameEngine.h"
#include "MenuButton.h"

class MapBuilderTileButton : public MenuButton {
public:
    //constants
    static const int WIDTH_ADJUSTOR = 38;
    static const int HEIGHT_ADJUSTOR = 20;
    //attributes
    RpgWorldBuilderScene* scene;
    BaseGameEngine* engine;
    MapTile* tile;

    //constructors
    MapBuilderTileButton() : MenuButton() {
        engine = NULL;
        tile = NULL;
        scene = NULL;
    }

    MapBuilderTileButton(MapTile* newTile, RpgWorldBuilderScene* gameScene) : MenuButton(newTile->textureKey, gameScene) {
        scene = gameScene;
        engine = gameScene->engine;
        tile = newTile;
        width = engine->screenWidth / WIDTH_ADJUSTOR;
        height = engine->screenHeight / HEIGHT_ADJUSTOR;
    }

    //destructor
    //~MapBuilderTileButton() {

    //}

    //methods
    void onClick() {
        scene->placingTile = true;
        scene->placingPortal = false;
        scene->tileBeingPlaced = tile;
    }
};

class MapBuilderPortalButton : public MenuButton {
public:
    //constants
    static const int WIDTH_ADJUSTOR = 38;
    static const int HEIGHT_ADJUSTOR = 20;
    //attributes
    RpgWorldBuilderScene* scene;
    BaseGameEngine* engine;
    int portalKey;

    //constructors
    MapBuilderPortalButton() : MenuButton() {
        engine = NULL;
        portalKey = -1;
        scene = NULL;
    }

    MapBuilderPortalButton(int newPortalKey, RpgWorldBuilderScene* gameScene) : MenuButton(newPortalKey, gameScene) {
        scene = gameScene;
        engine = gameScene->engine;
        portalKey = newPortalKey;
        width = engine->screenWidth / WIDTH_ADJUSTOR;
        height = engine->screenHeight / HEIGHT_ADJUSTOR;
    }

    //destructor
    //~MapBuilderTileButton() {

    //}

    //methods
    void onClick() {
        scene->placingPortal = true;
        scene->placingTile = false;
        scene->portalBeingPlaced = portalKey;
    }
};

class SaveMapBuilderButton : public MenuButton {
public:
    //attributes
    RpgWorldBuilderScene* scene;
    BaseGameEngine* engine;

    //constructors
    SaveMapBuilderButton() : MenuButton() {
        engine = NULL;
        scene = NULL;
    }

    SaveMapBuilderButton(int buttonTextureKey, RpgWorldBuilderScene* gameScene) : MenuButton(buttonTextureKey, gameScene) {
        scene = gameScene;
        engine = gameScene->engine;
    }

    void onClick() {
        SaveFile firstZoneFile = SaveFile("zoneOne.txt");
        firstZoneFile.addSaveObjectString(scene->currentZone.toSaveString());
        firstZoneFile.saveFile();
    }
};
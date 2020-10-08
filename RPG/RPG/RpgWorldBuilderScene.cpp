#include "RpgWorldBuilderScene.h"
#include "RpgGameEngine.h"
#include "RpgGameMenus.cpp"



//constants
const int DESIRED_TILES_DOWN = 10;
const int DESIRED_TILES_ACROSS = 19;

//constructor
RpgWorldBuilderScene::RpgWorldBuilderScene() : GameScene(){
    engine = NULL;
}

RpgWorldBuilderScene::RpgWorldBuilderScene(RpgGameEngine * gameEngine) : GameScene((BaseGameEngine *) gameEngine){
    engine = gameEngine;
}

void RpgWorldBuilderScene::loadSceneAssets() {
    texturesToLoad = {
        {BUTTON_BACKGROUND, "images/buttonBackground.png"},
        {GRASS, "images/grass.png"},
        {TREE, "images/tree.png"},
        {WATER, "images/water.png"},
        {MOUNTAIN, "images/mountain.png"},
        {PLAYER, "images/player.png"}
    };
}

void RpgWorldBuilderScene::setUpScene() {
    createTiles();

    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    firstZoneFile.loadFile();
    currentZone = ZoneMap(firstZoneFile.objects[0].rawString);

    ZoneBuilderMenu* zoneBuildMenu = new ZoneBuilderMenu(engine, BUILD_MENU, engine->screenWidth * LEFT_MENU_SIZE, engine->screenHeight, 0, 0);
    zoneBuildMenu->isActive = true;

    menus[BUILD_MENU] = zoneBuildMenu;

    //resize player texture to match tile size
    textures[PLAYER]->resize(tileHeight, tileWidth);
    //printf("%i, %i", textures[PLAYER].height);
    player = Player(textures[PLAYER], engine);
    int screenCoords[2];
    engine->coordsFromTileIndex(DESIRED_TILES_ACROSS / 2, DESIRED_TILES_DOWN / 2, screenCoords);
    playerScreenX = screenCoords[0];
    playerScreenY = screenCoords[1];
    player.setStartLocation(DESIRED_TILES_ACROSS / 2, DESIRED_TILES_DOWN / 2);
}

void RpgWorldBuilderScene::handleInput() {

}

void RpgWorldBuilderScene::sceneLogic() {

}

void RpgWorldBuilderScene::renderScene() {
    //fill screen with water
    for (size_t i = 0; i * tileHeight <= engine->screenHeight + tileHeight; i++)
    {
        for (size_t j = 0; j * tileWidth <= engine->screenWidth + tileWidth; j++) {
            engine->renderTexture(*textures[WATER], ((tileWidth * j) + engine->screenWidth * LEFT_MENU_SIZE) + (xOffset % tileWidth) - tileWidth, tileHeight * i + (yOffset % tileHeight) - tileHeight);
        }
    }

    //draw zone
    for (int i = 0; i < currentZone.tileMap.size(); i++) {
        for (int j = 0; j < currentZone.tileMap[i].size(); j++) {
            engine->renderTexture(*textures[mapTiles[currentZone.tileMap[i][j]].textureKey], (tileWidth * j) + engine->screenWidth * LEFT_MENU_SIZE + xOffset, tileHeight * i + yOffset);
        }
    }

    //draw tile being placed
    if (placingTile)
    {
        int x, y;
        int k[2], l[2];
        SDL_GetMouseState(&x, &y);
        engine->getTileIndexFromScreenCoords(x, y, k);
        engine->coordsFromTileIndex(k[0], k[1], l);
        if (engine->coordsAreOnDisplayedMapTile(x, y)) {
            engine->renderTexture(*textures[tileBeingPlaced->textureKey], l[0], l[1]);
        }
    }

    //draw menus
    for (auto menu : menus)
    {
        if (menu.second->isActive)
        {
            menu.second->draw();
        }
    }
}

//private methods
void RpgWorldBuilderScene::createTiles() {
    //create the different tiles
    mapTiles[GRASS] = MapTile(true, GRASS);
    mapTiles[TREE] = MapTile(false, TREE);
    mapTiles[WATER] = MapTile(false, WATER);
    mapTiles[MOUNTAIN] = MapTile(false, MOUNTAIN);


    //resize tiles depending on screen size
    int tilesImpliedWidth = engine->screenWidth / DESIRED_TILES_ACROSS;
    int tilesImpliedHeight = engine->screenHeight / DESIRED_TILES_DOWN;
    if (tilesImpliedHeight >= tilesImpliedWidth) {
        tileHeight = tilesImpliedHeight;
        tileWidth = tilesImpliedHeight;
    }
    else {
        tileHeight = tilesImpliedWidth;
        tileWidth = tilesImpliedWidth;
    }

    //for (auto i = mapTiles.begin(); i != mapTiles.end(); i++) {
        //engine->textures[i->second.textureKey].resize(tileHeight, tileWidth);
    //}
}

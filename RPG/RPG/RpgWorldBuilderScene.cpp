#include "RpgWorldBuilderScene.h"
#include "RpgGameEngine.h"
#include "RpgGameMenus.cpp"



//constants
const int DESIRED_TILES_DOWN = 10;
const int DESIRED_TILES_ACROSS = 19;

//constructor
RpgWorldBuilderScene::RpgWorldBuilderScene() : TileGridScene(){
    engine = NULL;
    leftButtonClicked = false;
    placingTile = false;
    desiredTilesAcross = DESIRED_TILES_ACROSS;
    desiredTilesDown = DESIRED_TILES_DOWN;
}

RpgWorldBuilderScene::RpgWorldBuilderScene(RpgGameEngine * gameEngine) : TileGridScene((BaseGameEngine *) gameEngine){
    engine = gameEngine;
    leftButtonClicked = false;
    placingTile = false;
    desiredTilesAcross = DESIRED_TILES_ACROSS;
    desiredTilesDown = DESIRED_TILES_DOWN;
}

void RpgWorldBuilderScene::loadSceneAssets() {
    TileGridScene::loadSceneAssets();
    texturesToLoad.merge(std::unordered_map<int, std::string>{
        {BUTTON_BACKGROUND, "images/buttonBackground.png"},
        {GRASS, "images/grass.png"},
        {TREE, "images/tree.png"},
        {WATER, "images/water.png"},
        {MOUNTAIN, "images/mountain.png"},
        {PLAYER, "images/player.png"}
    });
}

void RpgWorldBuilderScene::setUpScene() {
    TileGridScene::setUpScene();
    backDropTileKey = WATER;
    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    firstZoneFile.loadFile();
    currentZone = ZoneMap(firstZoneFile.objects[0].rawString);

    ZoneBuilderMenu* zoneBuildMenu = new ZoneBuilderMenu(engine, BUILD_MENU, mainCanvasStartX, engine->screenHeight, 0, 0);
    zoneBuildMenu->isActive = true;

    menus[BUILD_MENU] = zoneBuildMenu;
}

void RpgWorldBuilderScene::handleInput() {
    SDL_Event e;
    int x, y;
    int k[2];

    SDL_GetMouseState(&x, &y);
    if (x < engine->screenWidth * 0.01) {
        xOffset += 2;
    }
    if (x > engine->screenWidth * 0.99) {
        xOffset -= 2;
    }
    if (y < engine->screenHeight * 0.01) {
        yOffset += 2;
    }
    if (y > engine->screenHeight * 0.99) {
        yOffset -= 2;
    }

    //Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        for (auto menu : menus)
        {
            if (menu.second->isActive)
            {
                menu.second->handleEvent(&e);
            }
        }
        switch (e.type)
        {
        case SDL_QUIT:
            engine->gameRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                leftButtonClicked = true;
                if (placingTile)
                {
                    if (coordsAreOnDisplayedMapTile(x, y))
                    {
                        getTileIndexFromScreenCoords(x, y, k);
                        currentZone.tileMap[k[1]][k[0]] = tileBeingPlaced->textureKey;
                    }
                }
                break;
            default:
                break;
            }

            break;
        case SDL_MOUSEBUTTONUP:
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                leftButtonClicked = false;
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x, &y);
            if (placingTile)
            {
                if (coordsAreOnDisplayedMapTile(x, y) && leftButtonClicked)
                {
                    getTileIndexFromScreenCoords(x, y, k);
                    currentZone.tileMap[k[1]][k[0]] = tileBeingPlaced->textureKey;
                }
            }
            break;
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
            case SDLK_w:
                break;
            case SDLK_s:
                break;
            case SDLK_a:
                break;
            case SDLK_d:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (e.key.keysym.sym) {
            case SDLK_w:
                break;
            case SDLK_s:
                break;
            case SDLK_a:
                break;
            case SDLK_d:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void RpgWorldBuilderScene::sceneLogic() {

}

void RpgWorldBuilderScene::renderScene() {
    TileGridScene::renderScene();

    //draw tile being placed
    if (placingTile)
    {
        int x, y;
        int k[2], l[2];
        SDL_GetMouseState(&x, &y);
        getTileIndexFromScreenCoords(x, y, k);
        coordsFromTileIndex(k[0], k[1], l);
        if (coordsAreOnDisplayedMapTile(x, y)) {
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
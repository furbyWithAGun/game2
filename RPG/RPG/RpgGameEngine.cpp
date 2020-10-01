#include "RpgGameEngine.h"
#include <cmath>
#include "RpgGameButtons.cpp"
#include "RpgGameMenus.cpp"

//global vars
const int TILE_HEIGHT = 50;
const int TILE_WIDTH = 50;
const int DESIRED_TILES_DOWN = 20;
const int DESIRED_TILES_ACROSS = 38;
const double LEFT_MENU_SIZE = 0.1;


//methods
RpgGameEngine::RpgGameEngine() : BaseGameEngine("", 0, 0) {
    gameState = 0;
    tileHeight = TILE_HEIGHT;
    tileWidth = TILE_WIDTH;
    bool placingTile = false;
    MapTile* tileBeingPlaced = NULL;
    bool leftButtonClicked = false;
    xOffset = yOffset = 0;
}

RpgGameEngine::RpgGameEngine(std::string title, int width, int height) : BaseGameEngine( title, width, height) {
    gameState = 0;
    tileHeight = TILE_HEIGHT;
    tileWidth = TILE_WIDTH;
    bool placingTile = false;
    MapTile* tileBeingPlaced = NULL;
    mainCanvasStartX = width * LEFT_MENU_SIZE + 1;
    bool leftButtonClicked = false;
    xOffset = yOffset = 0;
}



void RpgGameEngine::loadAssets() {
    std::unordered_map<int, std::string> texturesToCreate = {
        {GRASS, "images/grass.png"},
        {TREE, "images/tree.png"},
        {WATER, "images/water.png"},
        {MOUNTAIN, "images/mountain.png"}
    };

    createMultipleTextures(texturesToCreate);
}

void RpgGameEngine::createTiles() {
    //create the different tiles
    mapTiles[GRASS] = MapTile(true, GRASS);
    mapTiles[TREE] = MapTile(true, TREE);
    mapTiles[WATER] = MapTile(true, WATER);
    mapTiles[MOUNTAIN] = MapTile(true, MOUNTAIN);


    //resize tiles depending on screen size
    int tilesImpliedWidth = screenWidth / DESIRED_TILES_ACROSS;
    int tilesImpliedHeight = screenHeight / DESIRED_TILES_DOWN;
    if (tilesImpliedHeight >= tilesImpliedWidth) {
        tileHeight = tilesImpliedHeight;
        tileWidth = tilesImpliedHeight;
    }
    else {
        tileHeight = tilesImpliedWidth;
        tileWidth = tilesImpliedWidth;
    }

    for (int i = 0; i < mapTiles.size(); i++) {
        textures[mapTiles[i].textureKey].resize(tileHeight, tileWidth);
    }
}

void RpgGameEngine::setUpGame() {

    gameState = LEVEL_DESIGN;

    createTiles();
    
    /*ZoneMap zoneOne = ZoneMap(0, {
        {WATER, WATER, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {WATER, GRASS, TREE, TREE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {WATER, GRASS, TREE, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        {GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS},
        });
    zoneOne.portals.push_back(ZonePortal(0, { 1,1 }, 1, {1,1}));*/

    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    //firstZoneFile.addSaveObjectString(engine.getSaveString());
    //firstZoneFile.saveFile();
    firstZoneFile.loadFile();
    currentZone = ZoneMap(firstZoneFile.objects[0].rawString);

    ZoneBuilderMenu* zoneBuildMenu = new ZoneBuilderMenu(this, BUILD_MENU, screenWidth * LEFT_MENU_SIZE, screenHeight, 0, 0);
    zoneBuildMenu->isActive = true;

    menus[BUILD_MENU] = zoneBuildMenu;
}

std::string RpgGameEngine::getSaveString() {
    std::string returnString = "";
    returnString += currentZone.toSaveString();
    return returnString;
}

void RpgGameEngine::handleInput() {
    SDL_Event e;
    int x, y;
    int k[2];

    SDL_GetMouseState(&x, &y);
    if (gameState == LEVEL_DESIGN)
    {
        if (x < screenWidth * 0.01) {
            xOffset += 1;
        }
        if (x > screenWidth * 0.99) {
            xOffset -= 1;
        }
        if (y < screenHeight * 0.01) {
            yOffset += 1;
        }
        if (y > screenHeight * 0.99) {
            yOffset -= 1;
        }
    }

    //Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        //pass event to all menus for handling
        

        switch (e.type)
        {
            case SDL_QUIT:
                gameRunning = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (e.button.button)
                {
                case SDL_BUTTON_LEFT:
                    leftButtonClicked = true;
                    for (auto menu : menus)
                    {
                        if (menu.second->isActive)
                        {
                            menu.second->handleEvent(&e);
                        }
                    }
                    if (placingTile)
                    {
                        if (mainCanvasStartX <= x)
                        {
                            getTileIndexFromScreenCoords(x, y, k);
                            currentZone.tileMap[k[1]][k[0]] = tileBeingPlaced->textureKey;
                        }
                    }
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
                    if (mainCanvasStartX <= x && leftButtonClicked)
                    {
                        getTileIndexFromScreenCoords(x, y, k);
                        currentZone.tileMap[k[1]][k[0]] = tileBeingPlaced->textureKey;
                    }
                }
                break;
            default:
                break;
        }
    }
}

void RpgGameEngine::gameLogic() {

}

void RpgGameEngine::gameRendering() {
    //clear screen
    SDL_SetRenderDrawColor(getMainRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(getMainRenderer());

    //draw zone
    for (int i = 0; i < currentZone.tileMap.size(); i++) {
        for (int j = 0; j < currentZone.tileMap[i].size(); j++) {
            renderTexture(textures[mapTiles[currentZone.tileMap[i][j]].textureKey], (tileWidth * j) + screenWidth * LEFT_MENU_SIZE + xOffset, tileHeight * i + yOffset);
        }
    }

    //draw tile being placed
    if (placingTile)
    {
        int x, y;
        int k[2];
        SDL_GetMouseState(&x, &y);
        getTileIndexFromScreenCoords(x, y, k);
        printf("%i %i \n", x, y);
        printf("%i %i \n", xOffset, yOffset);
        printf("%i %i \n", k[0], k[1]);
        int display1 = LEFT_MENU_SIZE * screenWidth + xOffset;
        int display2 = (currentZone.tileMap[0].size() * tileWidth) + xOffset + (LEFT_MENU_SIZE * screenWidth);
        printf("%i %i\n", display1, display2);
        if ((mainCanvasStartX <= x) && (LEFT_MENU_SIZE * screenWidth + xOffset <= x) && (currentZone.tileMap[0].size() * tileWidth + xOffset + LEFT_MENU_SIZE * screenWidth >= x) && (yOffset <= y) && (currentZone.tileMap.size() * tileWidth + yOffset >= y)) {
            renderTexture(textures[tileBeingPlaced->textureKey], (k[0] * tileWidth + LEFT_MENU_SIZE * screenWidth + xOffset), (k[1] * tileHeight) + yOffset);
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

    

    //Update screen
    SDL_RenderPresent(getMainRenderer());
}

void RpgGameEngine::getTileIndexFromScreenCoords(int x, int y, int tileIndices[2]) {
    tileIndices[0] = floor(((x - xOffset - screenWidth * LEFT_MENU_SIZE)) / tileWidth);
    tileIndices[1] =  floor((y - yOffset) / tileHeight);
}


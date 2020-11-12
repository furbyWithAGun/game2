#include "RpgWorldBuilderScene.h"
#include "BaseGameEngine.h"
#include "ZoneBuilderMenu.h"

//constants
const int DEFAULT_DESIRED_TILES_DOWN = 10;
const int DEFAULT_DESIRED_TILES_ACROSS = 19;
const int SCROLL_SPEED = 4;

//constructor
RpgWorldBuilderScene::RpgWorldBuilderScene() : TileGridScene(){
    init();
}

RpgWorldBuilderScene::RpgWorldBuilderScene(BaseGameEngine * gameEngine) : TileGridScene(gameEngine){
    init();
    engine = gameEngine;
}

void RpgWorldBuilderScene::init() {
    engine = NULL;
    tileBeingPlaced = NULL;
    placingTile = false;
    placingPortal = false;
    portalBeingPlaced = -1;
    controllerInterface = new RpgKeysMouseController();
}

void RpgWorldBuilderScene::declareSceneAssets() {
    TileGridScene::declareSceneAssets();
    texturesToLoad.insert({ BUTTON_BACKGROUND, "images/buttonBackground.png" });
}

void RpgWorldBuilderScene::setUpScene() {
    TileGridScene::setUpScene();
    backDropTileKey = WATER;
    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    firstZoneFile.loadFile();
    currentZone = ZoneMap(firstZoneFile.objects[0].rawString);

    ZoneBuilderMenu* zoneBuildMenu = new ZoneBuilderMenu(this, BUILD_MENU, mainCanvasStartX, engine->screenHeight, 0, 0);
    zoneBuildMenu->isActive = true;

    menus[BUILD_MENU] = zoneBuildMenu;
}

void RpgWorldBuilderScene::handleInput() {
    TileGridScene::handleInput();
    int tileCoords[2];
    InputMessage* message = new InputMessage();
    controllerInterface->populateMessageQueue();
    bool messageConsumedByMenus = false;
    while (controllerInterface->getNextMessage(message)) {
        if (!sendMessageToMenus(message))
        {
            switch (message->id)
            {
            case END_SCENE:
                endScene();
                break;
            case SELECT_ON:
                if (placingTile && coordsAreOnDisplayedMapTile(message->x, message->y))
                {
                    getTileIndexFromScreenCoords(message->x, message->y, tileCoords);
                    addCommand(InputMessage(PLACE_TILE, tileCoords[0], tileCoords[1], tileBeingPlaced->textureKey));
                }
                if (placingPortal && coordsAreOnDisplayedMapTile(message->x, message->y))
                {
                    getTileIndexFromScreenCoords(message->x, message->y, tileCoords);
                    addCommand(InputMessage(PLACE_PORTAL, tileCoords[0], tileCoords[1], portalBeingPlaced));
                }
                break;
            case SELECT_OFF:
                break;
            case POINTER_MOVEMENT:
                if (placingTile && coordsAreOnDisplayedMapTile(message->x, message->y) && controllerInterface->selectOn)
                {
                    getTileIndexFromScreenCoords(message->x, message->y, tileCoords);
                    addCommand(InputMessage(PLACE_TILE, tileCoords[0], tileCoords[1], tileBeingPlaced->textureKey));
                }
                if (placingPortal && coordsAreOnDisplayedMapTile(message->x, message->y) && controllerInterface->selectOn)
                {
                    getTileIndexFromScreenCoords(message->x, message->y, tileCoords);
                    addCommand(InputMessage(PLACE_PORTAL, tileCoords[0], tileCoords[1], portalBeingPlaced));
                }
                break;
            default:
                break;
            }
        }
    }
    delete message;
}

void RpgWorldBuilderScene::sceneLogic() {
    //handle commands
    InputMessage* message = new InputMessage();
    while (getNextCommand(message)) {
        switch (message->id)
        {
        case PLACE_TILE:
            currentZone.tileMap[message->y][message->x] = message->misc;
            break;
        case PLACE_PORTAL:
            currentZone.addZonePortal(message->misc, { message->x, message->y }, 0, { 0, 0 });
            break;
        default:
            break;
        }
    }
    delete message;
}

void RpgWorldBuilderScene::renderScene() {
    scrollCamera();
    int tileCoords[2], screenCoords[2];
    TileGridScene::renderScene();

    if (placingTile && coordsAreOnDisplayedMapTile(controllerInterface->latestXpos, controllerInterface->latestYpos))
    {
        getTileIndexFromScreenCoords(controllerInterface->latestXpos, controllerInterface->latestYpos, tileCoords);
        coordsFromTileIndex(tileCoords[0], tileCoords[1], screenCoords);
        renderTexture(tileBeingPlaced->textureKey, screenCoords[0], screenCoords[1], tileWidth, tileHeight);
    }

    if (placingPortal && coordsAreOnDisplayedMapTile(controllerInterface->latestXpos, controllerInterface->latestYpos))
    {
        getTileIndexFromScreenCoords(controllerInterface->latestXpos, controllerInterface->latestYpos, tileCoords);
        coordsFromTileIndex(tileCoords[0], tileCoords[1], screenCoords);
        renderTexture(portalBeingPlaced, screenCoords[0], screenCoords[1], tileWidth, tileHeight);
    }
}

void RpgWorldBuilderScene::scrollCamera() {
    int x, y;
    x = controllerInterface->latestXpos;
    y = controllerInterface->latestYpos;

    if (x < engine->screenWidth * 0.01) {
        xOffset += SCROLL_SPEED;
    }
    if (x > engine->screenWidth * 0.99) {
        xOffset -= SCROLL_SPEED;
    }
    if (y < engine->screenHeight * 0.01) {
        yOffset += SCROLL_SPEED;
    }
    if (y > engine->screenHeight * 0.99) {
        yOffset -= SCROLL_SPEED;
    }
}
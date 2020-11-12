#include "ZoneBuilderMenu.h"

//constructors
ZoneBuilderMenu::ZoneBuilderMenu() : GameMenu() {
    engine = NULL;
    scene = NULL;
}

ZoneBuilderMenu::ZoneBuilderMenu(RpgWorldBuilderScene* gameScene, int newId, int newWidth, int newHeight, int newXPos, int newYPos) : GameMenu(gameScene->engine, newId, newWidth, newHeight, newXPos, newYPos) {
    scene = gameScene;
    engine = gameScene->engine;
    buildButtons();
    elements.push_back(new MenuText(scene, "Tiles", { 255, 255, 255 }, scene->mainCanvasStartX / 4, engine->screenHeight * 0.01));
    elements.push_back(new MenuText(scene, "Portals", { 255, 255, 255 }, scene->mainCanvasStartX / 4, engine->screenHeight * 0.4));

    ScrollBox* scroller;
    scroller = new ScrollBox({ 100, 100, 100 }, scene, 300, 300, 200, 200);
    scroller->numElementsToDisplay = 3;
    scroller->addElement(new MenuText(scene, "Tiles1", { 255, 255, 255 }, scene->mainCanvasStartX / 4, engine->screenHeight * 0.01));
    scroller->addElement(new MenuText(scene, "Tiles2", { 255, 255, 255 }, scene->mainCanvasStartX / 4, engine->screenHeight * 0.01));
    scroller->addElement(new MenuText(scene, "Tiles3", { 255, 255, 255 }, scene->mainCanvasStartX / 4, engine->screenHeight * 0.01));
    scroller->addElement(new MenuText(scene, "Tiles4", { 255, 255, 255 }, scene->mainCanvasStartX / 4, engine->screenHeight * 0.01));

    elements.push_back(scroller);
}

//public methods
bool ZoneBuilderMenu::handleInput(InputMessage* message) {
    switch (message->id)
    {
    case BUTTON_1_ON:
        scene->placingTile = false;
        scene->placingPortal = false;
        break;
    default:
        break;
    }

    return GameMenu::handleInput(message);
}


//private methods
void ZoneBuilderMenu::buildButtons() {
    int x = 0;
    for (auto i = scene->mapTiles.begin(); i != scene->mapTiles.end(); i++)
    {
        MapBuilderTileButton* button;
        button = new MapBuilderTileButton(&i->second, scene);
        button->xpos = button->width / 2 + button->width * (x % 2) + button->width * (x % 2);
        button->ypos = (button->height * floor(x / 2) + button->height * floor(x / 2)) + engine->screenHeight * 0.05;
        buttons.push_back(button);
        elements.push_back(button);
        x++;
    }

    x = 0;
    for (int i = 0; i < scene->zonePortalImages.size(); i++)
    {
        MapBuilderPortalButton* button;
        button = new MapBuilderPortalButton(scene->zonePortalImages[i], scene);
        button->xpos = button->width / 2 + button->width * (x % 2) + button->width * (x % 2);
        button->ypos = (button->height * floor(x / 2) + button->height * floor(x / 2)) + engine->screenHeight * 0.45;
        buttons.push_back(button);
        elements.push_back(button);
        x++;
    }

    SaveMapBuilderButton* button = new SaveMapBuilderButton(BUTTON_BACKGROUND, scene);
    button->xpos = width * 0.2;
    button->ypos = height * 0.7;
    button->setText("Save Map");
    buttons.push_back(button);
    elements.push_back(button);
}

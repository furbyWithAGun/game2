#include "GameMenu.h"
#include "MenuButton.h"
#include "BaseGameEngine.h"
#include "MenuText.h"

const int NEXT_ELEMENT_ID_DEFAULT = 50000;

GameMenu::GameMenu() {
    init();
}

GameMenu::GameMenu(GameScene* gameScene, int newId, int newWidth, int newHeight, int newXPos, int newYPos) {
    init();
    scene = gameScene;
    engine = gameScene->engine;
    width = newWidth;
    height = newHeight;
    xpos = newXPos;
    ypos = newYPos;
    id = newId;
}

void GameMenu::init() {
    scene = NULL;
    engine = NULL;
    width = 0;
    height = 0;
    xpos = 0;
    ypos = 0;
    isActive = false;
    id = -1;
    r = g = b = 0x00;
    a = 0xFF;
    nextElementId = NEXT_ELEMENT_ID_DEFAULT;
}

GameMenu::~GameMenu() {
    buttons.clear();
    isActive = false;
    engine = NULL;
    int width = 0;
    int height = 0;
    int xpos = 0;
    int ypos = 0;
    id = r = g = b = a = 0;
}

void GameMenu::open() {
    isActive = true;
}

void GameMenu::close() {
    isActive = false;
}

void GameMenu::setRGBA(int newR, int newG, int newB, int newA) {
    r = newR;
    g = newG;
    b = newG;
    a = newA;
}

void GameMenu::draw() {
    scene->renderRectangle(xpos, ypos, width, height, r, g, b);

    for (auto element : elements)
    {
        element.second->draw();
    }
}

bool GameMenu::handleInput(InputMessage* message) {
    bool messageConsumed = false;
    for (auto element : elements)
    {
        if (element.second->handleInput(message))
        {
            messageConsumed = true;
        }
    }
    if (pointCollide(message->x, message->y))
    {
        messageConsumed = true;
    }
    return messageConsumed;
}

int GameMenu::getNextElementId() {
    while (elements.find(nextElementId) != elements.end())
    {
        nextElementId++;
    }
    return nextElementId;
}

int GameMenu::addElement(UiElement* newElement) {
    elements[getNextElementId()] = newElement;
    return nextElementId;
}

int GameMenu::addElement(int elementId, UiElement* newElement) {
    if (elements.find(elementId) == elements.end())
    {
        elements[elementId] = newElement;
        return elementId;
    }
    else {
        return -1;
    }
}

UiElement* GameMenu::getElementbyId(int elementId) {
    if (elements.find(elementId) != elements.end()) {
        return elements[elementId];
    }
    for (auto element : elements) {
        if (element.second->getElementbyId(elementId) != NULL)
        {
            return element.second->getElementbyId(elementId);
        }
    }
    return NULL;
}

bool GameMenu::pointCollide(int x, int y) {
    return (x >= xpos && x <= (xpos + width) && y >= ypos && y <= (ypos + height));
}



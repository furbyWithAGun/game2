#include "GameMenu.h"
#include "MenuButton.h"
#include "Sprite.h"
#include "BaseGameEngine.h"
#include "MenuText.h"

GameMenu::GameMenu() {
    init();
}

GameMenu::GameMenu(BaseGameEngine* gameEngine, int newId, int newWidth, int newHeight, int newXPos, int newYPos) {
    init();
    engine = gameEngine;
    width = newWidth;
    height = newHeight;
    xpos = newXPos;
    ypos = newYPos;
    id = newId;
}

void GameMenu::init() {
    engine = NULL;
    width = 0;
    height = 0;
    xpos = 0;
    ypos = 0;
    isActive = false;
    id = -1;
    r = g = b = 0x00;
    a = 0xFF;
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

void GameMenu::setRGBA(int newR, int newG, int newB, int newA) {
    r = newR;
    g = newG;
    b = newG;
    a = newA;
}

void GameMenu::draw() {
    //draw recangle on screen
    SDL_Rect fillRect = { 0, 0, width, height};
    SDL_SetRenderDrawColor(engine->getMainRenderer(), r, g, b, a);
    SDL_RenderFillRect(engine->getMainRenderer(), &fillRect);

    for (size_t i = 0; i < elements.size(); i++)
    {
        elements[i]->draw();
    }
}

bool GameMenu::handleInput(InputMessage* message) {
    bool messageConsumed = false;
    for (size_t i = 0; i < elements.size(); i++)
    {
        if (elements[i]->handleInput(message))
        {
            messageConsumed = true;
        }
    }
    return messageConsumed;
}



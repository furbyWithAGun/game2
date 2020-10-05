#include "GameMenu.h"

GameMenu::GameMenu() {
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

GameMenu::GameMenu(BaseGameEngine* gameEngine, int newId, int newWidth, int newHeight, int newXPos, int newYPos) {
    engine = gameEngine;
    width = newWidth;
    height = newHeight;
    xpos = newXPos;
    ypos = newYPos;
    isActive = false;
    id = newId;
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

    for (size_t i = 0; i < buttons.size(); i++)
    {
        buttons[i]->draw();
    }
}

void GameMenu::handleEvent(SDL_Event * e) {
    //handle event based on type
    switch (e->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        switch (e->button.button) 
        {
        case SDL_BUTTON_LEFT:
            int x, y;
            SDL_GetMouseState(&x, &y);
            for (size_t i = 0; i < buttons.size(); i++)
            {
                if (buttons[i]->pointCollision(x, y)) {
                    buttons[i]->onClick();
                }
            }
            break;
        case SDL_BUTTON_RIGHT:
            break;
        default:
            break;
        }
    default:
        break;
    }
}



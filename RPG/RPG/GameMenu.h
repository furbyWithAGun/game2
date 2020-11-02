#pragma once
#include "Sprite.h"
#include "BaseGameEngine.h"
#include "MenuButton.h"

class GameMenu
{
public:
    //attributes
    std::vector<MenuButton*> buttons;
    bool isActive;
    
    //constructors
    GameMenu();
    GameMenu(BaseGameEngine* gameEngine, int newId, int newWidth, int newHeight, int newXPos, int newYPos);

    //destructor
    ~GameMenu();

    //methods
    void setRGBA(int newR, int newG, int newB, int newA);
    virtual void draw();
    virtual void handleEvent(SDL_Event * e);

protected:
    //attributes
    BaseGameEngine* engine;
    int width;
    int height;
    int xpos;
    int ypos;
    int id, r, g, b, a;

private:
    //methods
    void init();
};


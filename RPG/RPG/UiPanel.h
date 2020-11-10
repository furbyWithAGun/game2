#pragma once
#include "BaseGameEngine.h"
class UiPanel
{
public:
    //attributes
    int x, y, width, height;
    SDL_Color colour;
    bool active;

    //constructors
    UiPanel();
    UiPanel(int xpos, int ypos, int panelWidth, int panelHeight);
    UiPanel(int xpos, int ypos, int panelWidth, int panelHeight, SDL_Color panelColour);

    //methods

private:
    //methods
    void init();
    void init(int xpos, int ypos, int panelWidth, int panelHeight);
};


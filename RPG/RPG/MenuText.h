#pragma once
#include <string>
#include "GameScene.h"
#include "UiElement.h"

class MenuText : public UiElement
{
public:
    //attributes
    GameScene* scene;
    SDL_Color colour;

    //constructors
    MenuText();
    MenuText(GameScene* newScene, std::string newText, int xpos, int ypos);
    MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos);
    MenuText(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight);
    MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight);

    //methods
    void draw();
    void setPos(int newX, int newY);

private:
    //methods
    void init();
    void init(GameScene* newScene, std::string newText);
};


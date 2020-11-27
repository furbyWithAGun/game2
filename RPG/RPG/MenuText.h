#pragma once
#include <string>
#include "GameScene.h"
#include "UiElement.h"

class MenuText : public UiElement
{
public:
    //attributes
    SDL_Color colour;

    //constructors
    MenuText();
    MenuText(GameScene* newScene, std::string newText, int xpos, int ypos);
    MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos);
    MenuText(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight);
    MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight);
    MenuText(int elementId, GameScene* newScene, std::string newText, int xpos, int ypos);
    MenuText(int elementId, GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos);
    MenuText(int elementId, GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight);
    MenuText(int elementId, GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight);

    //methods
    void draw();
    void setPos(int newX, int newY);

private:
    //methods
    void init();
    void init(std::string newText);
};


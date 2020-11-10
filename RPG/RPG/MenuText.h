#pragma once
#include <string>
#include "GameScene.h"

class MenuText
{
public:
    //attributes
    GameScene* scene;
    std::string text;
    SDL_Color colour;
    int x, y, width, height;

    //constructors
    MenuText();
    MenuText(GameScene* newScene, std::string newText, int xpos, int ypos);
    MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos);
    MenuText(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight);
    MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight);

    //methods
    void draw();
    void setText(std::string newText);
    void setPos(int newX, int newY);

private:
    //methods
    void init();
    void init(GameScene* newScene, std::string newText, int xpos, int ypos);
    void init(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight);
};

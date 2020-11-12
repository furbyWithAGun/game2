#pragma once
#include "UiElement.h"
#include "GameScene.h"

//class BaseGameEngine;

class MenuButton: public UiElement
{
public:
    //attributes
    GameScene* scene;
    int textTextureKey;
    std::string text;
    int textXoffset, textYoffset, textWidth, textHeight;

    //constructors
    MenuButton();
    MenuButton(int spriteTextureKey, GameScene* gamescene);

    //destructor
    //~MenuButton();

    //methods
    bool handleInput(InputMessage* message);
    virtual void onClick() {};
    void draw();
    void setText(std::string newText);
    void setPos(int x, int y);

private:
    //attributes

    //methods
    void init();
};


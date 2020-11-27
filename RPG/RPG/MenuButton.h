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
    int textXoffset, textYoffset, textWidth, textHeight;

    //constructors
    MenuButton();
    MenuButton(GameScene* gamescene, int spriteTextureKey);
    MenuButton(int elementID, GameScene* gamescene, int spriteTextureKey);

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


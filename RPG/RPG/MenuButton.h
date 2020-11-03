#pragma once
#include "Sprite.h"
#include "GameScene.h"

//class BaseGameEngine;

class MenuButton: public Sprite
{
public:
    //attributes
    GameScene* scene;
    int textTextureKey;
    std::string text;
    int textXoffset, textYoffset, textWidth, textHeight;

    //constructors
    MenuButton();
    MenuButton(Texture * spriteTexture, GameScene* gamescene);

    //destructor
    //~MenuButton();

    //methods
    virtual void onClick() {};
    void draw();
    void setText(std::string newText);
    void setPos(int x, int y);

private:
    //attributes

    //methods
    void init();
};


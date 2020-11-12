#pragma once
#include "InputMessage.h"
#include "Sprite.h"

class UiElement : public Sprite
{
public:
    //constructors
    UiElement();
    UiElement(int spriteTextureKey, GameScene* gameScene);
    UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);
    UiElement(SDL_Color spriteBackgroundColour, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);

    //methods
    virtual void draw();
    virtual bool handleInput(InputMessage* message) { return false; };
};


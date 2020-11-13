#pragma once
#include "InputMessage.h"
#include "Sprite.h"

class UiElement : public Sprite
{
public:
    //constructors
    UiElement();
    UiElement(int spriteTextureKey, GameScene* gameScene);
    UiElement(SDL_Color elementColour, GameScene* gameScene, int xpos, int ypos);
    UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos);
    UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);
    UiElement(GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);
    UiElement(SDL_Color spriteBackgroundColour, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);

    //methods
    virtual void draw();
    virtual bool handleInput(InputMessage* message) { return false; };
};


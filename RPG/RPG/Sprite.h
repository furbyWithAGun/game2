#pragma once
#include "Texture.h"
#include "GameScene.h"
#include "BaseGameEngine.h"

class Sprite
{
public:
    //attributes
    int width, height, xpos, ypos;
    int textureKey;
    SDL_Color backgroundColour;
    bool active;
    bool drawBackground;

    //constructor
    Sprite();
    Sprite(GameScene* gameScene);
    Sprite(int spriteTextureKey, GameScene* gameScene);
    Sprite(SDL_Color spriteBackgroundColour, GameScene* gameScene);
    Sprite(SDL_Color spriteBackgroundColour, GameScene* gameScene, int x, int y, int spriteWidth, int spriteHeight);
    Sprite(int spriteTextureKey, GameScene* gameScene, int x, int y, int spriteWidth, int spriteHeight);

    //methods
    bool pointCollision(int x, int y);
    virtual void draw();

protected:
    GameScene* scene;

private:
    //methods
    void init();
    void init(SDL_Color spriteBackgroundColour, GameScene* gameScene);
    void init(int spriteTextureKey, GameScene* gameScene);
    void init(GameScene* gameScene);
};


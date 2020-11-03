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
    bool active;

    //constructor
    Sprite();
    Sprite(GameScene* gameScene);
    Sprite(int spriteTextureKey, GameScene* gameScene);

    //deconstructor
    //~Sprite();

    //methods
    bool pointCollision(int x, int y);
    virtual void draw();

protected:
    GameScene* scene;

private:
    //methods
    void init();
    void init(GameScene* gameScene);
};


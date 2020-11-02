#pragma once
#include "Texture.h"
#include "GameScene.h"
#include "BaseGameEngine.h"

class Sprite
{
public:
    //attributes
    int width, height, xpos, ypos;
    Texture* texture;
    bool active;

    //constructor
    Sprite(Texture * spriteTexture, GameScene * gameScene);
    Sprite(GameScene * gameScene);
    Sprite();

    //deconstructor
    ~Sprite();

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


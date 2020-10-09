#pragma once
#include "Texture.h"
#include "GameScene.h"
#include "BaseGameEngine.h"

class Sprite
{
    public:
        //attributes
        int width, height, xpos, ypos;
        Texture * texture;

        //constructor
        Sprite(Texture * spriteTexture, GameScene * gameScene);
        Sprite();

        //deconstructor
        ~Sprite();

        //methods
        bool pointCollision(int x, int y);
        void draw();

    private:
       GameScene* scene;
};


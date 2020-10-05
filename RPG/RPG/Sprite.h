#pragma once
#include "Texture.h"
#include "BaseGameEngine.h"

class Sprite
{
    public:
        //attributes
        int width, height, xpos, ypos;
        Texture * texture;

        //constructor
        Sprite(Texture * spriteTexture, BaseGameEngine * gameEngine);
        Sprite();

        //deconstructor
        ~Sprite();

        //methods
        bool pointCollision(int x, int y);
        void draw();

    private:
        BaseGameEngine* engine;
};


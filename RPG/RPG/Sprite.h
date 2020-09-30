#pragma once
#include "Texture.h"

class Sprite
{
    public:
        //attributes
        int width, height, xpos, ypos;
        Texture texture;

        //constructor
        Sprite(Texture spriteTexture);
        Sprite();

        //deconstructor
        //~Sprite();

        //methods
        bool pointCollision(int x, int y);
};


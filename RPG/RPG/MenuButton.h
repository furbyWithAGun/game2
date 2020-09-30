#pragma once
#include "Sprite.h"

class BaseGameEngine;

class MenuButton: public Sprite
{
    public:
        //attributes
        BaseGameEngine * engine;

        //constructors
        MenuButton();
        MenuButton(Texture spriteTexture, BaseGameEngine * gameEngine);

        //methods
        void onClick();
        void draw();

};


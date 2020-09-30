#pragma once
#include "Sprite.h"
#include "BaseGameEngine.h"

//class BaseGameEngine;

class MenuButton: public Sprite
{
    public:
        //attributes
        BaseGameEngine * engine;

        //constructors
        MenuButton();
        MenuButton(Texture spriteTexture, BaseGameEngine * gameEngine);

        //destructor
        //~MenuButton();

        //methods
        virtual void onClick() {};
};


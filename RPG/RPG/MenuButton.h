#pragma once
#include "Sprite.h"
#include "BaseGameEngine.h"

//class BaseGameEngine;

class MenuButton: public Sprite
{
    public:
        //attributes
        BaseGameEngine * engine;
        Texture textTexture;
        std::string text;
        int textXoffset, textYoffset;

        //constructors
        MenuButton();
        MenuButton(Texture * spriteTexture, BaseGameEngine * gameEngine);

        //destructor
        ~MenuButton();

        //methods
        virtual void onClick() {};
        void draw();
        void setText(std::string newText);
        void setPos(int x, int y);
};


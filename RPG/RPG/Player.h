#pragma once
#include "Unit.h"

class RpgGameEngine;

class Player : public Unit
{
public:
    //attributes
    

    //constructor
    Player();
    Player(Texture * spriteTexture, RpgGameEngine* gameEngine);
};


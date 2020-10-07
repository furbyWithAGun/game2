#pragma once
#include "Unit.h"

class RpgGameEngine;

class Player : public Unit
{
public:
    //attributes
    std::vector<int> startLocation;

    //constructor
    Player();
    Player(Texture * spriteTexture, RpgGameEngine* gameEngine);
    
    //methods
    void setStartLocation(int x, int y);
    void updatePlayer();
};


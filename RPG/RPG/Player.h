#pragma once
#include "Unit.h"

class TileGridScene;

class Player : public Unit
{
public:
    //attributes
    //std::vector<int> startLocation;

    //constructor
    Player();
    Player(Texture * spriteTexture, TileGridScene* gameScene);
    
    //methods
    //void setStartLocation(int x, int y);
    void updatePlayer();
};


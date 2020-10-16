#pragma once
#include "RpgGameConstants.h"

class Attack
{
public:
    //attributes
    int type, range, cooldownTime, cooldown;

    //constructors
    Attack();
    Attack(int newType);

    //methods
    virtual void startAttack(int direction, int xTile, int yTile) {};
    virtual void startAttack(int xTileStart, int yTileStart, int xTileEnd, int yTileEnd) {};
};


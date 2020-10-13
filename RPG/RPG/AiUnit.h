#pragma once
#include "Unit.h"
class AiUnit : public Unit
{
public:
    //attributes
    bool isHostile;

    //constructor
    AiUnit();
    AiUnit(Texture* spriteTexture, TileGridScene* gameScene);

    //methods
    void update();

private:
    //attribues
    double chanceToMoveEachTick;

    //methods
    void randomMovement();
};


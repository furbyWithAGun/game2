#pragma once
#include "Unit.h"
class AiUnit : public Unit
{
public:
    //attributes
    bool isHostile;

    //constructor
    AiUnit();
    AiUnit(TileGridScene* gameScene);

    //methods
    void update();

private:
    //attribues
    double chanceToMoveEachTick;

    //methods
    void randomMovement();
};


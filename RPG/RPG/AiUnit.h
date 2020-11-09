#pragma once
#include "Unit.h"

class RpgOverWorldScene;

class AiUnit : public Unit
{
public:
    //attributes
    bool isHostile;

    //constructor
    AiUnit();
    AiUnit(int unitType);
    AiUnit(int unitType, TileGridScene* gameScene);
    AiUnit(int unitType, TileGridScene* gameScene, int startX, int startY);

    //methods
    void update();

private:
    //attribues
    double chanceToMoveEachTick;

    //methods
    void randomMovement();
    bool attackNearbyUnit();
    bool meleeAttackUnitInDirection(int direction);
    void init();
};


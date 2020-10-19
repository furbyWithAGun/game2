#pragma once
#include "RpgGameConstants.h"

class Unit;

class Attack
{
public:
    //attributes
    int type, range, cooldownTime, cooldown;
    Unit* owningUnit;

    //constructors
    Attack();
    Attack(int newType, Unit* newOwningUnit);

    //methods
    virtual void startAttack();
    virtual void processHit(Unit* targetUnit) {};
    virtual void update() {};
};


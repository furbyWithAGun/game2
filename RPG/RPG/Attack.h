#pragma once
#include "RpgGameConstants.h"

class Unit;

class Attack
{
public:
    //attributes
    int type, range, cooldownTimeLeft, cooldown, attackDelay, attackTime;
    Unit* owningUnit;

    //constructors
    Attack();
    Attack(int newType, Unit* newOwningUnit);

    //methods
    virtual void startAttack();
    virtual void processHit(Unit* targetUnit) {};
    virtual void update();
    virtual void processAttack() {};
};


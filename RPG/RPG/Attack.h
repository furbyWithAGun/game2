#pragma once
#include "RpgGameConstants.h"

class Unit;

class Attack
{
public:
    //attributes
    int type, range, cooldownTimeLeft, cooldown;
    Unit* owningUnit;

    //constructors
    Attack();
    Attack(int newType, Unit* newOwningUnit);

    //methods
    virtual int startAttack() { return IDLE_DOWN; };
    virtual void processHit(Unit* targetUnit) {};
    virtual void update() {};
};


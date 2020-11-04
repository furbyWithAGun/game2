#pragma once
#include "UnitState.h"
class IdleState : public UnitState
{
public:
    //attributes

    //constructors
    IdleState();
    IdleState(int id, Unit* controlledUnit);

    //methods
    int update() override;
    int handleInput() override;

protected:
    //attributes

private:
    //methods
};


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
    virtual int update();
    virtual int handleInput();

protected:
    //attributes
    int id;

private:
    //methods
};


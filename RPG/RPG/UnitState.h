#pragma once

class Unit;

class UnitState
{
public:
    //attributes

    //constructors
    UnitState();
    UnitState(int id, Unit* controlledUnit);

    //methods
    virtual int update() { return id; };
    virtual int handleInput() { return id; };

protected:
    //attributes
    int id;
    Unit* unit;

private:
    //methods
    void init();
};


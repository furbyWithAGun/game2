#include "IdleState.h"
#include "Unit.h"

//constructors
IdleState::IdleState() : UnitState() {

}

IdleState::IdleState(int newId, Unit* controlledUnit) : UnitState(newId, controlledUnit) {

}

//public methods
int IdleState::update() {
    UnitState::update();
    if (unit->isMoving())
    {
        return UNIT_MOVING;
    }
    else {
        return id;
    }
}

int IdleState::handleInput() {
    return id;
}

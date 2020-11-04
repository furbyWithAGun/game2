#include "MovingState.h"
#include "IdleState.h"
#include "Unit.h"

//constructors
MovingState::MovingState() : UnitState() {

}

MovingState::MovingState(int newId, Unit* controlledUnit) : UnitState(newId, controlledUnit) {

}

//public methods
int MovingState::update() {
    UnitState::update();
    unit->updateMovement();
    if (!unit->isStatic) {
        unit->updateCoords();
    }
    if (unit->isMoving())
    {
        return id;
    }
    else {
        return UNIT_IDLE;
    }
    return id;
}

int MovingState::handleInput() {
    return id;
}

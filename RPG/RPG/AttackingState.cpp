#include "AttackingState.h"
#include "MovingState.h"
#include "IdleState.h"
#include "Unit.h"

//constructors
AttackingState::AttackingState() : UnitState() {

}

AttackingState::AttackingState(int newId, Unit* controlledUnit) : UnitState(newId, controlledUnit) {

}

//public methods
int AttackingState::update() {
    UnitState::update();
    if (!unit->attacking)
    {
        return UNIT_IDLE;
    }
}

int AttackingState::handleInput() {
    return id;
}

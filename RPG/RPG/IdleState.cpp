#include "IdleState.h"

//constructors
IdleState::IdleState() : UnitState() {

}

IdleState::IdleState(int newId, Unit* controlledUnit) : UnitState(newId, controlledUnit) {

}

//public methods
int IdleState::update() {
    return id;
}

int IdleState::handleInput() {
    return id;
}

#include "AttackingState.h"
#include "MovingState.h"
#include "IdleState.h"
#include "Unit.h"
#include "RpgOverWorldScene.h"

//constructors
AttackingState::AttackingState() : UnitState() {

}

AttackingState::AttackingState(int newId, Unit* controlledUnit) : UnitState(newId, controlledUnit) {

}

//public methods
int AttackingState::update() {
    UnitState::update();
    if (unit->activeAttack->cooldown - unit->activeAttack->cooldownTimeLeft >= unit->activeAttack->attackTime) {
        return UNIT_IDLE;
    }
    return id;
}

int AttackingState::handleInput(InputMessage* message) {
    return id;
}

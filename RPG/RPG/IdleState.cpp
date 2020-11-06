#include "IdleState.h"
#include "Unit.h"
#include "RpgOverWorldScene.h"

//constructors
IdleState::IdleState() : UnitState() {

}

IdleState::IdleState(int newId, Unit* controlledUnit) : UnitState(newId, controlledUnit) {

}

//public methods
int IdleState::update() {
    UnitState::update();
    return id;
}

int IdleState::handleInput(InputMessage* message) {
    switch (message->id)
    {
    case PERFORM_MAIN_ATTACK:
        unit->faceCoords(message->x, message->y);
        if (unit->performAttack(MAIN_ATTACK))
        {
            return UNIT_ATTACKING;
        }
        break;
    case START_MOVE_UP:
        unit->movingUp = true;
        return UNIT_MOVING;
        break;
    case START_MOVE_DOWN:
        unit->movingDown = true;
        return UNIT_MOVING;
        break;
    case START_MOVE_LEFT:
        unit->movingLeft = true;
        return UNIT_MOVING;
        break;
    case START_MOVE_RIGHT:
        unit->movingRight = true;
        return UNIT_MOVING;
        break;
    default:
        break;
    }
    return id;
}

void IdleState::updateAnimation() {
    switch (unit->directionFacing) {
    case UP:
        unit->setAnimation(IDLE_UP);
        break;
    case DOWN:
        unit->setAnimation(IDLE_DOWN);
        break;
    case RIGHT:
        unit->setAnimation(IDLE_RIGHT);
        break;
    case LEFT:
        unit->setAnimation(IDLE_LEFT);
        break;
    default:
        unit->setAnimation(IDLE_DOWN);
        break;
    }
}

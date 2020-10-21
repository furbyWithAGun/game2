#include "BasicMeleeAttack.h"
#include "Unit.h"

BasicMeleeAttack::BasicMeleeAttack() : Attack() {
    cooldown = 200;
    attackTime = 200;
    cooldownTimeLeft = 0;
    attackDelay = 0;
}

BasicMeleeAttack::BasicMeleeAttack(int newType, Unit* newOwningUnit) : Attack(newType, newOwningUnit){
    cooldown = 200;
    attackTime = 200;
    cooldownTimeLeft = 0;
    attackDelay = 0;
}

void BasicMeleeAttack::startAttack() {
    Attack::startAttack();
    switch (owningUnit->directionFacing)
    {
    case UP_LEFT:
        owningUnit->playAnimation(ATTACK_UP_LEFT, attackTime);
        break;
    case UP:
        owningUnit->playAnimation(ATTACK_UP, attackTime);
        break;
    case UP_RIGHT:
        owningUnit->playAnimation(ATTACK_UP_RIGHT, attackTime);
        break;
    case RIGHT:
        owningUnit->playAnimation(ATTACK_RIGHT, attackTime);
        break;
    case DOWN_RIGHT:
        owningUnit->playAnimation(ATTACK_DOWN_RIGHT, attackTime);
        break;
    case DOWN:
        owningUnit->playAnimation(ATTACK_DOWN, attackTime);
        break;
    case DOWN_LEFT:
        owningUnit->playAnimation(ATTACK_DOWN_LEFT, attackTime);
        break;
    case LEFT:
        owningUnit->playAnimation(ATTACK_LEFT, attackTime);
        break;
    default:
        break;
    }
}


void BasicMeleeAttack::processHit(Unit* targetUnit) {
    targetUnit->assignDamage(10);
}

void BasicMeleeAttack::processAttack() {
    int attackTargetLocation[2];
    Unit* targetUnit;
    owningUnit->getLocationUnitIsFacing(attackTargetLocation);
    targetUnit = owningUnit->scene->getUnitAtLocation(attackTargetLocation[0], attackTargetLocation[1]);
    if (targetUnit != NULL and targetUnit != owningUnit) {
        processHit(targetUnit);
    }
}

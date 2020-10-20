#include "BasicMeleeAttack.h"
#include "Unit.h"

BasicMeleeAttack::BasicMeleeAttack() : Attack() {

}

BasicMeleeAttack::BasicMeleeAttack(int newType, Unit* newOwningUnit) : Attack(newType, newOwningUnit){

}

void BasicMeleeAttack::startAttack() {
    if (cooldownTimeLeft <= 0){
        cooldownTimeLeft = cooldown;
        switch (owningUnit->directionFacing)
        {
        case UP_LEFT:
            owningUnit->playAnimation(ATTACK_UP_LEFT);
            break;
        case UP:
            owningUnit->playAnimation(ATTACK_UP);
            break;
        case UP_RIGHT:
            owningUnit->playAnimation(ATTACK_UP_RIGHT);
            break;
        case RIGHT:
            owningUnit->playAnimation(ATTACK_RIGHT);
            break;
        case DOWN_RIGHT:
            owningUnit->playAnimation(ATTACK_DOWN_RIGHT);
            break;
        case DOWN:
            owningUnit->playAnimation(ATTACK_DOWN);
            break;
        case DOWN_LEFT:
            owningUnit->playAnimation(ATTACK_DOWN_LEFT);
            break;
        case LEFT:
            owningUnit->playAnimation(ATTACK_LEFT);
            break;
        default:
            break;
        }
    }
}

void BasicMeleeAttack::update() {
    if (cooldownTimeLeft == attackDelay)
    {
        int attackTargetLocation[2];
        Unit* targetUnit;
        owningUnit->getLocationUnitIsFacing(attackTargetLocation);
        targetUnit = owningUnit->scene->getUnitAtLocation(attackTargetLocation[0], attackTargetLocation[1]);
        if (targetUnit != NULL and targetUnit != owningUnit) {
            processHit(targetUnit);
        }
    }
    cooldownTimeLeft -= 1;
}

void BasicMeleeAttack::processHit(Unit* targetUnit) {
    targetUnit->assignDamage(10);
}

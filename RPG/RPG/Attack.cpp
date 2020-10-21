#include "Attack.h"
#include "Unit.h"

Attack::Attack() {
    owningUnit = NULL;
    type = 0;
    range = 1;
    cooldown = 1;
    attackTime = 1;
    cooldownTimeLeft = 0;
    attackDelay = 0;
}

Attack::Attack(int newType, Unit* newOwningUnit){
    type = newType;
    owningUnit = newOwningUnit;
    range = 1;
    cooldown = 1;
    attackTime = 1;
    cooldownTimeLeft = 0;
    attackDelay = 0;
}

void Attack::startAttack() {
    if (cooldownTimeLeft <= 0) {
        cooldownTimeLeft = cooldown;
        owningUnit->attacking = true;
    }
}

void Attack::update() {
    if (cooldown - cooldownTimeLeft == attackDelay) {
        processAttack();
    }
    if (cooldown - cooldownTimeLeft >= attackTime)
    {
        owningUnit->attacking = false;
    }
    cooldownTimeLeft -= 1;
}
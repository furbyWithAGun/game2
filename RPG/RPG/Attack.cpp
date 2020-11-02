#include "Attack.h"
#include "Unit.h"

Attack::Attack() {
    init();
}

Attack::Attack(int newType, Unit* newOwningUnit){
    init();
    type = newType;
    owningUnit = newOwningUnit;
}

void Attack::init() {
    range = 1;
    damage = 1;
    cooldown = 1;
    attackTime = 1;
    cooldownTimeLeft = 0;
    attackDelay = 0;
    type = MELEE;
    owningUnit = NULL;
}

bool Attack::startAttack() {
    if (cooldownTimeLeft <= 0) {
        cooldownTimeLeft = cooldown;
        owningUnit->attacking = true;
        return true;
    }
    return false;
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
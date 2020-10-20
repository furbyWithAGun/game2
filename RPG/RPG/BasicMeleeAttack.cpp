#include "BasicMeleeAttack.h"
#include "Unit.h"

BasicMeleeAttack::BasicMeleeAttack() : Attack() {

}

BasicMeleeAttack::BasicMeleeAttack(int newType, Unit* newOwningUnit) : Attack(newType, newOwningUnit){

}

void BasicMeleeAttack::startAttack(int xTile, int yTile) {
    if (cooldownTimeLeft <= 0){
        cooldownTimeLeft = cooldown;
    }
}

void BasicMeleeAttack::update() {
    cooldownTimeLeft -= 1;
}

void BasicMeleeAttack::processHit(Unit* targetUnit) {
    targetUnit->assignDamage(10);
}

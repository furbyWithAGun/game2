#include "BasicMeleeAttack.h"
#include "Unit.h"

BasicMeleeAttack::BasicMeleeAttack() : Attack() {

}

BasicMeleeAttack::BasicMeleeAttack(int newType, Unit* newOwningUnit) : Attack(newType, newOwningUnit){

}

void BasicMeleeAttack::startAttack(int xTile, int yTile) {

}

void BasicMeleeAttack::processHit(Unit* targetUnit) {
    targetUnit->assignDamage(10);
}

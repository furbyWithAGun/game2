#include "Attack.h"

Attack::Attack() {
    type = 0;
    range = 1;
    cooldown = 0;
    cooldownTime = 1;
}

Attack::Attack(int newType, Unit* newOwningUnit){
    type = newType;
    owningUnit = newOwningUnit;
    range = 1;
    cooldown = 0;
    cooldownTime = 1;
}
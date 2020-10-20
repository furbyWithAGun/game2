#include "Attack.h"

Attack::Attack() {
    type = 0;
    range = 1;
    cooldown = 1;
    cooldownTimeLeft = 0;
    attackDelay = 0;
}

Attack::Attack(int newType, Unit* newOwningUnit){
    type = newType;
    owningUnit = newOwningUnit;
    range = 1;
    cooldown = 1;
    cooldownTimeLeft = 0;

}
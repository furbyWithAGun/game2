#pragma once
#include "Attack.h"
#include "Animation.h"


class GameScene;
class Unit;

class BasicMeleeAttack : public Attack
{
public:
    //attribues
    int animationKey;

    //constructors
    BasicMeleeAttack();
    BasicMeleeAttack(int newType, Unit* newOwningUnit);

    //methods
    void startAttack() override;
    void update();
    void processHit(Unit* targetUnit);
};


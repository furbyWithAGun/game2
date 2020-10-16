#pragma once
#include "Attack.h"
#include "Animation.h"

class GameScene;

class BasicMeleeAttack : public Attack
{
public:
    //attribues
    Animation animation;

    //constructors
    BasicMeleeAttack();
    BasicMeleeAttack(int newType);

    //methods
};


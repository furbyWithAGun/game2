#include "Rat.h"
#include "BasicMeleeAttack.h"

const int RAT_MAX_HEALTH = 100;
const int RAT_SPEED = 2;

Rat::Rat() : AiUnit() {
    init();
}

Rat::Rat(TileGridScene* gameScene) : AiUnit(gameScene) {
    init(gameScene);
}

Rat::Rat(TileGridScene* gameScene, int startX, int startY) : AiUnit(gameScene, startX, startY) {
    init(gameScene);
}

void Rat::init() {
    speed = RAT_SPEED;
    health = RAT_MAX_HEALTH;
    maxHealth = RAT_MAX_HEALTH;
    equipedAttacks[MAIN_ATTACK] = new BasicMeleeAttack(MELEE, this); //potential memory leak
    activeAttack = equipedAttacks[MAIN_ATTACK];
}

void Rat::init(TileGridScene* gameScene) {
    init();
    createAnimations();
    resize(scene->tileWidth, scene->tileWidth);
}


void Rat::createAnimations() {
    addAnimation(IDLE_UP_LEFT,RAT_IDLE_DOWN, 1, 10);
    addAnimation(IDLE_UP,RAT_IDLE_DOWN, 1, 10);
    addAnimation(IDLE_UP_RIGHT,RAT_IDLE_DOWN, 1, 10);
    addAnimation(IDLE_RIGHT,RAT_IDLE_DOWN, 1, 10);
    addAnimation(IDLE_DOWN_RIGHT,RAT_IDLE_DOWN, 1, 10);
    addAnimation(IDLE_DOWN,RAT_IDLE_DOWN, 1, 10);
    addAnimation(IDLE_DOWN_LEFT,RAT_IDLE_DOWN, 1, 10);
    addAnimation(IDLE_LEFT,RAT_IDLE_DOWN, 1, 10);

    addAnimation(MOVE_DOWN,RAT_IDLE_DOWN, 1, 20);
    addAnimation(MOVE_UP,RAT_IDLE_DOWN, 1, 20);
    addAnimation(MOVE_RIGHT,RAT_IDLE_DOWN, 1, 20);
    addAnimation(MOVE_LEFT,RAT_IDLE_DOWN, 1, 20);

    addAnimation(ATTACK_UP_LEFT,RAT_IDLE_DOWN, 1, 10, false);
    addAnimation(ATTACK_UP,RAT_IDLE_DOWN, 1, 10, false);
    addAnimation(ATTACK_UP_RIGHT,RAT_IDLE_DOWN, 1, 10, false);
    addAnimation(ATTACK_RIGHT,RAT_IDLE_DOWN, 1, 10, false);
    addAnimation(ATTACK_DOWN_RIGHT,RAT_IDLE_DOWN, 1, 10, false);
    addAnimation(ATTACK_DOWN,RAT_IDLE_DOWN, 1, 10, false);
    addAnimation(ATTACK_DOWN_LEFT,RAT_IDLE_DOWN, 1, 10, false);
    addAnimation(ATTACK_LEFT,RAT_IDLE_DOWN, 1, 10, false);
}
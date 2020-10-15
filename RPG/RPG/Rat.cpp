#include "Rat.h"

Rat::Rat() : AiUnit() {
    speed = RAT_SPEED;
}

Rat::Rat(TileGridScene* gameScene) : AiUnit(gameScene) {
    speed = RAT_SPEED;
    scene = gameScene;
    createAnimations();
    resize(scene->tileWidth, scene->tileWidth);
}

void Rat::createAnimations() {
    addAnimation(IDLE_UP_LEFT, RAT, 1, 10);
    addAnimation(IDLE_UP, RAT, 1, 10);
    addAnimation(IDLE_UP_RIGHT, RAT, 1, 10);
    addAnimation(IDLE_RIGHT, RAT, 1, 10);
    addAnimation(IDLE_DOWN_RIGHT, RAT, 1, 10);
    addAnimation(IDLE_DOWN, RAT, 1, 10);
    addAnimation(IDLE_DOWN_LEFT, RAT, 1, 10);
    addAnimation(IDLE_LEFT, RAT, 1, 10);

    addAnimation(MOVE_DOWN, RAT, 1, 20);
    addAnimation(MOVE_UP, RAT, 1, 20);
    addAnimation(MOVE_RIGHT, RAT, 1, 20);
    addAnimation(MOVE_LEFT, RAT, 1, 20);
    
    /*addAnimation(IDLE_UP_LEFT, RAT_IDLE_UP_LEFT_SHEET, 1, 10);
    addAnimation(IDLE_UP, RAT_IDLE_UP_SHEET, 1, 10);
    addAnimation(IDLE_UP_RIGHT, RAT_IDLE_UP_RIGHT_SHEET, 1, 10);
    addAnimation(IDLE_RIGHT, RAT_IDLE_RIGHT_SHEET, 1, 10);
    addAnimation(IDLE_DOWN_RIGHT, RAT_IDLE_DOWN_RIGHT_SHEET, 1, 10);
    addAnimation(IDLE_DOWN, RAT_IDLE_DOWN_SHEET, 1, 10);
    addAnimation(IDLE_DOWN_LEFT, RAT_IDLE_DOWN_LEFT_SHEET, 1, 10);
    addAnimation(IDLE_LEFT, RAT_IDLE_LEFT_SHEET, 1, 10);

    addAnimation(MOVE_DOWN, RAT_MOVE_DOWN_SHEET, 2, 20);
    addAnimation(MOVE_UP, RAT_MOVE_DOWN_SHEET, 2, 20);
    addAnimation(MOVE_RIGHT, RAT_MOVE_DOWN_SHEET, 2, 20);
    addAnimation(MOVE_LEFT, RAT_MOVE_DOWN_SHEET, 2, 20);*/
}
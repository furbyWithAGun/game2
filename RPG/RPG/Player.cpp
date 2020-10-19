#include "Player.h"
#include "TileGridScene.h"
#include "BasicMeleeAttack.h"

Player::Player() : Unit() {
    isStatic = true;
    speed = PLAYER_SPEED;
    mainAttack = new BasicMeleeAttack(MELEE, this);
}

Player::Player(TileGridScene* gameScene) : Unit(gameScene) {
    scene = gameScene;
    isStatic = true;
    speed = PLAYER_SPEED;
    createAnimations();
    resize(scene->tileWidth, scene->tileWidth);
    mainAttack = new BasicMeleeAttack(MELEE, this);
}

Player::Player(TileGridScene* gameScene, int startX, int startY) : Unit(gameScene, startX, startY) {
    scene = gameScene;
    isStatic = true;
    speed = PLAYER_SPEED;
    createAnimations();
    resize(scene->tileWidth, scene->tileWidth); mainAttack = new BasicMeleeAttack(MELEE, this);
}

void Player::update() {
    Unit::update();

    //centre on screen by changing scene x and y offsets
    int coords[2];
    int destCoords[2];
    scene->coordsFromTileIndex(tileLocation[0], tileLocation[1], coords);
    scene->coordsFromTileIndex(tileDestination[0], tileDestination[1], destCoords);
    int x = coords[0] + (destCoords[0] - coords[0]) * (1 - leftToMove);
    int y = coords[1] + (destCoords[1] - coords[1]) * (1 - leftToMove);
    scene->xOffset += xpos - x;
    scene->yOffset += ypos - y;
}

void Player::faceMouseDirection(int x, int y) {
    if (!isMoving())
    {
        if (x < xpos && y < ypos)
        {
            directionFacing = UP_LEFT;
        }
        else if (x >= xpos && x <= xpos + width && y < ypos) {
            directionFacing = UP;
        }
        else if (x > xpos + width && y < ypos) {
            directionFacing = UP_RIGHT;
        }
        else if (x > xpos + width && y > ypos && y < ypos + height) {
            directionFacing = RIGHT;
        }
        else if (x > xpos + width && y > ypos + height) {
            directionFacing = DOWN_RIGHT;
        }
        else if (x >= xpos && x <= xpos + width && y > ypos + height) {
            directionFacing = DOWN;
        }
        else if (x < xpos && y > ypos + height) {
            directionFacing = DOWN_LEFT;
        }
        else if (x < xpos && y > ypos && y < ypos + height) {
            directionFacing = LEFT;
        }
    }
}

//private methods
void Player::createAnimations() {
    addAnimation(IDLE_UP_LEFT, PLAYER_IDLE_UP_LEFT_SHEET, 1, 10);
    addAnimation(IDLE_UP, PLAYER_IDLE_UP_SHEET, 1, 10);
    addAnimation(IDLE_UP_RIGHT, PLAYER_IDLE_UP_RIGHT_SHEET, 1, 10);
    addAnimation(IDLE_RIGHT, PLAYER_IDLE_RIGHT_SHEET, 1, 10);
    addAnimation(IDLE_DOWN_RIGHT, PLAYER_IDLE_DOWN_RIGHT_SHEET, 1, 10);
    addAnimation(IDLE_DOWN, PLAYER_IDLE_DOWN_SHEET, 1, 10);
    addAnimation(IDLE_DOWN_LEFT, PLAYER_IDLE_DOWN_LEFT_SHEET, 1, 10);
    addAnimation(IDLE_LEFT, PLAYER_IDLE_LEFT_SHEET, 1, 10);

    addAnimation(MOVE_DOWN, PLAYER_MOVE_DOWN_SHEET, 2, 20);
    addAnimation(MOVE_UP, PLAYER_MOVE_DOWN_SHEET, 2, 20);
    addAnimation(MOVE_RIGHT, PLAYER_MOVE_DOWN_SHEET, 2, 20);
    addAnimation(MOVE_LEFT, PLAYER_MOVE_DOWN_SHEET, 2, 20);

    addAnimation(ATTACK_UP_LEFT, BASIC_MELEE_ATTACK_SHEET, 2, 10, false);
    addAnimation(ATTACK_UP, BASIC_MELEE_ATTACK_SHEET, 2, 10, false);
    addAnimation(ATTACK_UP_RIGHT, BASIC_MELEE_ATTACK_SHEET, 2, 10, false);
    addAnimation(ATTACK_RIGHT, BASIC_MELEE_ATTACK_SHEET, 2, 10, false);
    addAnimation(ATTACK_DOWN_RIGHT, BASIC_MELEE_ATTACK_SHEET, 2, 10, false);
    addAnimation(ATTACK_DOWN, BASIC_MELEE_ATTACK_DOWN_SHEET, 2, 20, false);
    addAnimation(ATTACK_DOWN_LEFT, BASIC_MELEE_ATTACK_SHEET, 2, 10, false);
    addAnimation(ATTACK_LEFT, BASIC_MELEE_ATTACK_SHEET, 2, 10, false);
}


#include "Unit.h"
#include"BaseGameEngine.h"

Unit::Unit() : Sprite() {
    tileLocation = {0, 0};
    tileDestination = {0, 0};
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    engine = NULL;
}

Unit::Unit(Texture * spriteTexture, BaseGameEngine* gameEngine) : Sprite(spriteTexture, gameEngine) {
    tileLocation = {0, 0};
    tileDestination = {0, 0};
    int coords[2];
    //engine->coords;
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    engine = gameEngine;
}

//destructor
Unit::~Unit() {
    //delete &tileLocation;
    //delete &tileDestination;
    name = "";
    health = 0;
    speed = 0;
    leftToMove = 0;
    engine = NULL;
}

void Unit::startMovement(int direction) {
    if (leftToMove == 0)
    {
        leftToMove = 1;
        switch (direction)
        {
        case MOVE_UP:
            tileDestination[1] = tileLocation[1] - 1;
            break;
        case MOVE_DOWN:
            tileDestination[1] = tileLocation[1] + 1;
            break;
        case MOVE_RIGHT:
            tileDestination[0] = tileDestination[0] + 1;
            break;
        case MOVE_LEFT:
            tileDestination[0] = tileDestination[0] - 1;
            break;
        default:
            break;
        }
    }
}

void Unit::updateMovement() {
    leftToMove = leftToMove - speed / 100;
    if (leftToMove <= 0) {
        leftToMove = 0;
        tileLocation[0] = tileDestination[1];
        tileLocation[0] = tileDestination[1];
    }
}
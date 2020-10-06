#include "Unit.h"
#include"RpgGameEngine.h"

Unit::Unit() : Sprite() {
    tileLocation = {0, 0};
    tileDestination = {0, 0};
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    engine = NULL;
}

Unit::Unit(Texture * spriteTexture, RpgGameEngine* gameEngine) : Sprite(spriteTexture, gameEngine) {
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    engine = gameEngine;
    tileLocation = {0, 0};
    tileDestination = { 0, 0 };
    setTileLocation(0, 0);
}

//destructor
Unit::~Unit() {
    //&tileLocation;
    //&tileDestination;
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
        setTileLocation(tileDestination[0], tileDestination[1]);
    }
}

void Unit::setTileLocation(int x, int y) {
    int coords[2];
    tileLocation[0] = x;
    tileLocation[1] = y;
    engine->coordsFromTileIndex(tileLocation[0], tileLocation[1], coords);
    xpos = coords[0];
    ypos = coords[1];

}
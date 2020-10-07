#include "Unit.h"
#include"RpgGameEngine.h"

Unit::Unit() : Sprite() {
    tileLocation = {0, 0};
    tileDestination = {0, 0};
    name = "";
    health = 1;
    speed = 2;
    leftToMove = 0;
    engine = NULL;
    isStatic = false;
}

Unit::Unit(Texture * spriteTexture, RpgGameEngine* gameEngine) : Sprite(spriteTexture, gameEngine) {
    name = "";
    health = 1;
    speed = 2;
    leftToMove = 0;
    engine = gameEngine;
    tileLocation = {0, 0};
    tileDestination = { 0, 0 };
    setTileLocation(0, 0);
    isStatic = false;
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
            tileDestination[0] = tileLocation[0] + 1;
            break;
        case MOVE_LEFT:
            tileDestination[0] = tileLocation[0] - 1;
            break;
        default:
            break;
        }
    }
}

void Unit::updateMovement() {
    if (leftToMove > 0) {
        leftToMove = leftToMove - (double)speed / 100;
        if (!isStatic) {
            updateCoords();
        }
    }
    if (leftToMove <= 0) {
        leftToMove = 0;
        if (tileDestination[0] != tileLocation[0] || tileDestination[1] != tileLocation[1]) {
            setTileLocation(tileDestination[0], tileDestination[1]);
        } 
    }
}

void Unit::setTileLocation(int x, int y) {
    printf("setting location");
    tileLocation[0] = x;
    tileLocation[1] = y;
    tileDestination[0] = x;
    tileDestination[1] = y;
    if (!isStatic) {
        updateCoords();
    }
}

void Unit::updateCoords() {
    int coords[2];
    int destCoords[2];
    engine->coordsFromTileIndex(tileLocation[0], tileLocation[1], coords);
    engine->coordsFromTileIndex(tileDestination[0], tileDestination[1], destCoords);
    xpos = coords[0] + (destCoords[0] - coords[0]) * (1 - leftToMove);
    ypos = coords[1] + (destCoords[1] - coords[1]) * (1 - leftToMove);
}
#include "Unit.h"
#include"GameScene.h"

Unit::Unit() : Sprite() {
    tileLocation = {0, 0};
    tileDestination = {0, 0};
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    isStatic = false;
}

Unit::Unit(Texture * spriteTexture, TileGridScene* gameScene) : Sprite(spriteTexture, gameScene) {
    scene = gameScene;
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
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
}

void Unit::startMovement(int direction) {
    if (leftToMove == 0)
    {
        leftToMove = 1;
        switch (direction)
        {
        case UP:
            if (scene->isTilePassable(tileLocation[0], tileLocation[1] - 1))
            {
                directionFacing = UP;
                tileDestination[1] = tileLocation[1] - 1;
            }
            break;
        case DOWN:
            if (scene->isTilePassable(tileLocation[0], tileLocation[1] + 1))
            {
                directionFacing = DOWN;
                tileDestination[1] = tileLocation[1] + 1;
            }            
            break;
        case RIGHT:
            if (scene->isTilePassable(tileLocation[0] + 1, tileLocation[1]))
            {
                directionFacing = RIGHT;
                tileDestination[0] = tileLocation[0] + 1;
            }
            break;
        case LEFT:
            if (scene->isTilePassable(tileLocation[0] - 1, tileLocation[1]))
            {
                directionFacing = LEFT;
                tileDestination[0] = tileLocation[0] - 1;
            }
            break;
        default:
            break;
        }
    }
}

void Unit::updateMovement() {
    if (leftToMove > 0) {
        leftToMove = leftToMove - (double)speed / 100;
    }
    if (leftToMove <= 0) {
        leftToMove = 0;
        if (tileDestination[0] != tileLocation[0] || tileDestination[1] != tileLocation[1]) {
            setTileLocation(tileDestination[0], tileDestination[1]);
        } 
    }
}

void Unit::setTileLocation(int x, int y) {
    tileLocation[0] = x;
    tileLocation[1] = y;
    tileDestination[0] = x;
    tileDestination[1] = y;
}

void Unit::updateCoords() {
    int coords[2];
    int destCoords[2];
    scene->coordsFromTileIndex(tileLocation[0], tileLocation[1], coords);
    scene->coordsFromTileIndex(tileDestination[0], tileDestination[1], destCoords);
    xpos = coords[0] + (destCoords[0] - coords[0]) * (1 - leftToMove);
    ypos = coords[1] + (destCoords[1] - coords[1]) * (1 - leftToMove);
}

void Unit::setStartLocation(int x, int y) {
    tileLocation[0] = x;
    tileLocation[1] = y;
    tileDestination[0] = x;
    tileDestination[1] = y;
    int screenCoords[2];
    scene->coordsFromTileIndex(x, y, screenCoords);
    xpos = screenCoords[0];
    ypos = screenCoords[1];
}

void Unit::draw()
{
    if (!isStatic) {
        updateCoords();
    }
    Sprite::draw();
}

void attack() {

}

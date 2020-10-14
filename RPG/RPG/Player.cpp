#include "Player.h"
#include "TileGridScene.h"

Player::Player() : Unit() {
    isStatic = true;
    speed = PLAYER_SPEED;
}

Player::Player(TileGridScene* gameScene) : Unit(gameScene) {
    scene = gameScene;
    isStatic = true;
    speed = PLAYER_SPEED;
    createAnimations();
    resize(scene->tileWidth, scene->tileWidth);
}

void Player::updatePlayer() {
    if (leftToMove != 0 && currentAnimation != &animations[MOVE_DOWN])
    {
        currentAnimation = &animations[MOVE_DOWN];
        currentAnimation->resetAnimation(1);
    }
    else if(leftToMove == 0) {
        currentAnimation = &animations[IDLE];
    }
    Unit::update();
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

//private methods
void Player::createAnimations() {
    addAnimation(IDLE, PLAYER_IDLE_SHEET, 1, 10);
    addAnimation(MOVE_DOWN, PLAYER_MOVE_DOWN_SHEET, 2, 20);
}


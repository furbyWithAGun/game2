#include "Player.h"
#include "TileGridScene.h"

Player::Player() : Unit() {
    //startLocation = { 0, 0 };
    isStatic = true;
}

Player::Player(TileGridScene* gameScene) : Unit(gameScene) {
    scene = gameScene;
    //startLocation = { 0, 0 };
    isStatic = true;
}

void Player::updatePlayer() {
    Unit::update();
    updateMovement();
    int coords[2];
    int destCoords[2];
    scene->coordsFromTileIndex(tileLocation[0], tileLocation[1], coords);
    scene->coordsFromTileIndex(tileDestination[0], tileDestination[1], destCoords);
    int x = coords[0] + (destCoords[0] - coords[0]) * (1 - leftToMove);
    int y = coords[1] + (destCoords[1] - coords[1]) * (1 - leftToMove);
    scene->xOffset += xpos - x;
    scene->yOffset += ypos - y;
}
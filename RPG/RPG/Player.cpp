#include "Player.h"
#include "TileGridScene.h"

Player::Player() : Unit() {
    //startLocation = { 0, 0 };
    isStatic = true;
}

Player::Player(Texture * spriteTexture, TileGridScene* gameScene) : Unit(spriteTexture, gameScene) {
    scene = gameScene;
    //startLocation = { 0, 0 };
    isStatic = true;
}

void Player::updatePlayer() {
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

//void Player::setStartLocation(int x, int y) {
//    tileLocation[0] = x;
//    tileLocation[1] = y;
//    tileDestination[0] = x;
//    tileDestination[1] = y;
//    int screenCoords[2];
//    scene->coordsFromTileIndex(x, y, screenCoords);
//    xpos = screenCoords[0];
//    ypos = screenCoords[1];
//}
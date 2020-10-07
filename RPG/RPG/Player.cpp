#include "Player.h"
#include "RpgGameEngine.h"

Player::Player() : Unit() {
    startLocation = { 0, 0 };
    isStatic = true;
}

Player::Player(Texture * spriteTexture, RpgGameEngine* gameEngine) : Unit(spriteTexture, gameEngine) {
    startLocation = { 0, 0 };
    isStatic = true;
}

void Player::updatePlayer() {
    updateMovement();
    int coords[2];
    int destCoords[2];
    engine->coordsFromTileIndex(tileLocation[0], tileLocation[1], coords);
    engine->coordsFromTileIndex(tileDestination[0], tileDestination[1], destCoords);
    int x = coords[0] + (destCoords[0] - coords[0]) * (1 - leftToMove);
    int y = coords[1] + (destCoords[1] - coords[1]) * (1 - leftToMove);
    engine->xOffset += engine->playerScreenX - x;
    engine->yOffset += engine->playerScreenY -y;
    //printf("x: %i\ny: %i\nplayerScreenX: %i\nplayerScreenY: %i\nxOffset: %i\nyOffset: %i\nxpos: %i\nypos: %i\n", x, y, engine->playerScreenX, engine->playerScreenY, engine->xOffset, engine->yOffset, xpos, ypos);
}

void Player::setStartLocation(int x, int y) {
    startLocation[0] = x;
    startLocation[1] = y;
    tileLocation[0] = x;
    tileLocation[1] = y;
    tileDestination[0] = x;
    tileDestination[1] = y;
    xpos = engine->playerScreenX;
    ypos = engine->playerScreenY;
}
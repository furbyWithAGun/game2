#include "Sprite.h"

Sprite::Sprite(Texture spriteTexture, BaseGameEngine * gameEngine) {
    texture = spriteTexture;
    width = texture.width;
    height = texture.height;
    xpos = 0;
    ypos = 0;
    engine = gameEngine;
}

Sprite::Sprite() {
    width = 0;
    height = 0;
    xpos = 0;
    ypos = 0;
    engine = NULL;
}

bool Sprite::pointCollision(int x, int y) {
    return (x >= xpos && x <= (xpos + width) && y >= ypos && y <= (ypos + height));
}

void Sprite::draw() {
    engine->renderTexture(texture, xpos, ypos, width, height);
}
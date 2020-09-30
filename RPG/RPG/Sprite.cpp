#include "Sprite.h"

Sprite::Sprite(Texture spriteTexture) {
    texture = spriteTexture;
    width = texture.width;
    height = texture.height;
    xpos = 0;
    ypos = 0;
}

Sprite::Sprite() {
    width = texture.width;
    height = texture.height;
}

bool Sprite::pointCollision(int x, int y) {
    return (x >= xpos && x <= (xpos + width) && y >= ypos && y <= (ypos + height));
}
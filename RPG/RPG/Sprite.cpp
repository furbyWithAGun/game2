#include "Sprite.h"

Sprite::Sprite(Texture spriteTexture) {
    texture = spriteTexture;
    width = texture.width;
    height = texture.height;
}
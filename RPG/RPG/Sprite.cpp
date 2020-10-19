#include "Sprite.h"

Sprite::Sprite(Texture * spriteTexture, GameScene * gameScene) {
    texture = spriteTexture;
    width = texture->width;
    height = texture->height;
    xpos = 0;
    ypos = 0;
    scene = gameScene;
    active = true;
}

Sprite::Sprite( GameScene* gameScene) {
    texture = NULL;
    width = texture->width;
    height = texture->height;
    xpos = 0;
    ypos = 0;
    scene = gameScene;
    active = true;
}

Sprite::Sprite() {
    texture = NULL;
    width = 0;
    height = 0;
    xpos = 0;
    ypos = 0;
    scene = NULL;
    active = true;
}

Sprite::~Sprite() {
    texture = NULL;
    width = 0;
    height = 0;
    xpos = 0;
    ypos = 0;
    scene = NULL;
    active = false;
}

bool Sprite::pointCollision(int x, int y) {
    return (x >= xpos && x <= (xpos + width) && y >= ypos && y <= (ypos + height));
}

void Sprite::draw() {
    scene->renderTexture(texture, xpos, ypos, width, height);
}
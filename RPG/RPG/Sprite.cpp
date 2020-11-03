#include "Sprite.h"

Sprite::Sprite() {
    init();
}

Sprite::Sprite(GameScene* gameScene) {
    init(gameScene);
}

Sprite::Sprite(int spriteTextureKey, GameScene * gameScene) {
    init(gameScene);
    textureKey = spriteTextureKey;
    width = scene->engine->getTextureWidth(spriteTextureKey);
    height = scene->engine->getTextureHeight(spriteTextureKey);
}

void Sprite::init() {
    textureKey = -1;
    width = 0;
    height = 0;
    xpos = 0;
    ypos = 0;
    scene = NULL;
    active = true;
}

void Sprite::init(GameScene* gameScene) {
    init();
    scene = gameScene;
}

//Sprite::~Sprite() {
//    texture = NULL;
//    width = 0;
//    height = 0;
//    xpos = 0;
//    ypos = 0;
//    scene = NULL;
//    active = false;
//}

bool Sprite::pointCollision(int x, int y) {
    return (x >= xpos && x <= (xpos + width) && y >= ypos && y <= (ypos + height));
}

void Sprite::draw() {
    if (textureKey != -1)
    {
        scene->renderTexture(textureKey, xpos, ypos, width, height);
    }
}
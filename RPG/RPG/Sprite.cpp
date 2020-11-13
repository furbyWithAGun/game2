#include "Sprite.h"
const SDL_Color DEFAULT_BACKGROUND_COLOUR = { 0, 0, 0 };

Sprite::Sprite() {
    init();
}

Sprite::Sprite(GameScene* gameScene) {
    init(gameScene);
}

Sprite::Sprite(int spriteTextureKey, GameScene * gameScene) {
    init(spriteTextureKey, gameScene);
    width = scene->engine->getTextureWidth(spriteTextureKey);
    height = scene->engine->getTextureHeight(spriteTextureKey);
}

Sprite::Sprite(SDL_Color spriteBackgroundColour, GameScene* gameScene) {
    init(spriteBackgroundColour, gameScene);
}

Sprite::Sprite(SDL_Color spriteBackgroundColour, GameScene* gameScene, int x, int y) {
    init(spriteBackgroundColour, gameScene);
    xpos = x;
    ypos = y;
}

Sprite::Sprite(int spriteTextureKey, GameScene* gameScene, int x, int y) {
    init(spriteTextureKey, gameScene);
    xpos = x;
    ypos = y;
}


Sprite::Sprite(SDL_Color spriteBackgroundColour, GameScene* gameScene, int x, int y, int spriteWidth, int spriteHeight) {
    init(spriteBackgroundColour, gameScene);
    xpos = x;
    ypos = y;
    width = spriteWidth;
    height = spriteHeight;
}

Sprite::Sprite(int spriteTextureKey, GameScene* gameScene, int x, int y, int spriteWidth, int spriteHeight) {
    init(spriteTextureKey, gameScene);
    xpos = x;
    ypos = y;
    width = spriteWidth;
    height = spriteHeight;
}

void Sprite::init() {
    textureKey = -1;
    width = -1;
    height = -1;
    xpos = 0;
    ypos = 0;
    scene = NULL;
    active = true;
    drawBackground = true;
    backgroundColour = DEFAULT_BACKGROUND_COLOUR;
}

void Sprite::init(GameScene* gameScene) {
    init();
    scene = gameScene;
}

void Sprite::init(SDL_Color spriteBackgroundColour, GameScene* gameScene) {
    init(gameScene);
    backgroundColour = spriteBackgroundColour;
}

void Sprite::init(int spriteTextureKey, GameScene* gameScene) {
    init(gameScene);
    textureKey = spriteTextureKey;
}

//methods
bool Sprite::pointCollision(int x, int y) {
    return (x >= xpos && x <= (xpos + width) && y >= ypos && y <= (ypos + height));
}

void Sprite::draw() {
    if (active) {
        if (drawBackground)
        {
            scene->engine->renderRectangle(xpos, ypos, width, height, backgroundColour.r, backgroundColour.g, backgroundColour.b);
        }

        if (textureKey != -1)
        {
            scene->renderTexture(textureKey, xpos, ypos, width, height);
        }
    }
}
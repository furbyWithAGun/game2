#include "GameScene.h"
#include "BaseGameEngine.h"

//constructors
GameScene::GameScene() {
    init();
}

GameScene::GameScene(BaseGameEngine * newEngine) {
    init();
    engine = newEngine;
}

void GameScene::init() {
    engine = NULL;
    sceneRunning = true;
}

//public methods
void GameScene::renderTexture(Texture* texture, int x, int y)
{
    engine->renderTexture(texture, x, y);
}

void GameScene::renderTexture(Texture*  texture, int x, int y, int width, int height)
{
    engine->renderTexture(texture, x, y, width, height);
}

void GameScene::renderTexture(int textureKey, int x, int y)
{
    engine->renderTexture(textureKey, x, y);
}

void GameScene::renderTexture(int textureKey, int x, int y, int width, int height)
{
    engine->renderTexture(textureKey, x, y, width, height);
}

void GameScene::endScene() {
    sceneRunning = false;
    SDL_AtomicUnlock(&engine->sceneRunningLock);
}



#include "GameScene.h"
#include "BaseGameEngine.h"

//constructors
GameScene::GameScene() {
    engine = NULL;
    sceneRunning = true;
}

GameScene::GameScene(BaseGameEngine * newEngine) {
    engine = newEngine;
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
    engine->renderTexture(textures[textureKey], x, y);
}

void GameScene::renderTexture(int textureKey, int x, int y, int width, int height)
{
    engine->renderTexture(textures[textureKey], x, y, width, height);
}

void GameScene::endScene() {
    sceneRunning = false;
    SDL_AtomicUnlock(&engine->sceneRunningLock);
}



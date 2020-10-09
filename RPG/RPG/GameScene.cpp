#include "GameScene.h"
#include "BaseGameEngine.h"

GameScene::GameScene() {
    engine = NULL;
}

GameScene::GameScene(BaseGameEngine * newEngine) {
    engine = newEngine;
}

void GameScene::renderTexture(Texture* texture, int x, int y)
{
    engine->renderTexture(texture, x, y);
}

void GameScene::renderTexture(Texture*  texture, int x, int y, int width, int height)
{
    engine->renderTexture(texture, x, y, width, height);
}



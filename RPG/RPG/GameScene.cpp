#include "GameScene.h"
#include "BaseGameEngine.h"

GameScene::GameScene() {
    engine = NULL;
}

GameScene::GameScene(BaseGameEngine * newEngine) {
    engine = newEngine;
}



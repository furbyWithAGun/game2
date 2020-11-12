#pragma once
#include "TileGridScene.h"
#include "Player.h"
#include "AiUnit.h"
#include "RpgKeysMouseController.h"

class RpgOverWorldScene : public TileGridScene
{
public:
    //attributes
    int frames = 0;
    Player* player;

    //constructors
    RpgOverWorldScene();
    RpgOverWorldScene(BaseGameEngine* gameEngine);

    void declareSceneAssets();
    void setUpScene() override;
    void handleInput() override;
    void sceneLogic() override;
    void renderScene() override;

private:
    //attributes
    AiUnit enemy;
    AiUnit enemy2;

    //methods
    void init();
};


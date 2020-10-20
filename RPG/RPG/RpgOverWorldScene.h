#pragma once
#include "TileGridScene.h"
#include "Player.h"
#include "AiUnit.h"

class RpgOverWorldScene : public TileGridScene
{
public:
    //attributes
    int frames = 0;

    //constructora
    RpgOverWorldScene();
    RpgOverWorldScene(BaseGameEngine* gameEngine);

    void loadSceneAssets();
    void setUpScene() override;
    void handleInput() override;
    void sceneLogic() override;
    void renderScene() override;

private:
    //attributes
    Player* player;
    AiUnit enemy;
    AiUnit enemy2;
    bool wKeyDown, sKeyDown, dKeyDown, aKeyDown;
};


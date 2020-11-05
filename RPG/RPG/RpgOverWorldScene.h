#pragma once
#include "TileGridScene.h"
#include "Player.h"
#include "AiUnit.h"
#include "RpgOverWorldSceneKeysMouseController.h"

enum OVERWORLD_INPUT_MESSAGES {
    END_SCENE,
    MAIN_ATTACK,
    START_MOVE_UP,
    START_MOVE_DOWN,
    START_MOVE_RIGHT,
    START_MOVE_LEFT,
    STOP_MOVE_UP,
    STOP_MOVE_DOWN,
    STOP_MOVE_RIGHT,
    STOP_MOVE_LEFT
};

class RpgOverWorldScene : public TileGridScene
{
public:
    //attributes
    int frames = 0;

    //constructora
    RpgOverWorldScene();
    RpgOverWorldScene(BaseGameEngine* gameEngine);

    void declareSceneAssets();
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

    //methods
    void init();
};


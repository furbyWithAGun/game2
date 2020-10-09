#pragma once
#include "TileGridScene.h"
class RpgOverWorldScene : public TileGridScene
{
public:
    //attributes

    //constructora
    RpgOverWorldScene();
    RpgOverWorldScene(BaseGameEngine* gameEngine);

    void loadSceneAssets();
    void setUpScene() override;
    bool handleInput() override;
    bool sceneLogic() override;
    bool renderScene() override;
};


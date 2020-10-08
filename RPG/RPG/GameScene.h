#pragma once
#include "Texture.h"
#include <unordered_map>

class BaseGameEngine;

class GameScene
{
public:
    //attributes
    BaseGameEngine* engine;
    std::unordered_map<int, Texture *> textures;
    std::unordered_map<int, std::string> texturesToLoad;

    //constructor
    GameScene();
    GameScene(BaseGameEngine * gameEngine);

    //methods
    virtual void loadSceneAssets() {};
    virtual void setUpScene() {};
    virtual void handleInput() {};
    virtual void sceneLogic() {};
    virtual void renderScene() {};

};


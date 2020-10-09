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
    void renderTexture(Texture* texture, int x, int y);
    void renderTexture(Texture* texture, int x, int y, int width, int height);
    virtual void loadSceneAssets() {};
    virtual void setUpScene() {};
    virtual bool handleInput() { return true; };
    virtual bool sceneLogic() { return true; };
    virtual bool renderScene() { return true; };

};


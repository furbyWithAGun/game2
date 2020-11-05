#pragma once
#include "Texture.h"
#include "ControllerInterface.h"
#include <unordered_map>
class BaseGameEngine;

class GameScene
{
    friend class BaseGameEngine;
public:
    //attributes
    BaseGameEngine* engine;
    bool sceneRunning;
    
    //constructor
    GameScene();
    GameScene(BaseGameEngine * gameEngine);

    //methods
    virtual void handleInput() {};
    virtual void sceneLogic() {};
    virtual void renderScene() {};
    void renderTexture(Texture* texture, int x, int y);
    void renderTexture(Texture* texture, int x, int y, int width, int height);
    void renderTexture(int textureKey, int x, int y);
    void renderTexture(int textureKey, int x, int y, int width, int height);

protected:
    //attributes
    std::unordered_map<int, std::string> texturesToLoad;
    ControllerInterface* controllerInterface;

    //methods
    void endScene();
    virtual void declareSceneAssets() {};
    virtual void setUpScene() {};
    

private:
    //attributes
    
    //methods
    void init();
};


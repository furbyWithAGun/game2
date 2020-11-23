#pragma once
#include "Texture.h"
#include "ControllerInterface.h"
#include <unordered_map>
#include "GameMenu.h"

class BaseGameEngine;

class GameScene
{
    friend class BaseGameEngine;
public:
    //attributes
    BaseGameEngine* engine;
    bool sceneRunning;
    bool gettingTextInput;
    
    //constructor
    GameScene();
    GameScene(BaseGameEngine * gameEngine);

    //methods
    virtual void handleInput();
    virtual void sceneLogic() {};
    virtual void renderScene() {};
    void renderTexture(Texture* texture, int x, int y);
    void renderTexture(Texture* texture, int x, int y, int width, int height);
    void renderTexture(int textureKey, int x, int y);
    void renderTexture(int textureKey, int x, int y, int width, int height);
    bool getNextCommand(InputMessage* message);
    void addCommand(InputMessage* message);
    void addCommand(InputMessage message);
    void openMenu(int menuId);

protected:
    //attributes
    std::unordered_map<int, std::string> texturesToLoad;
    ControllerInterface* controllerInterface;
    std::vector<InputMessage*> commandQueue;
    std::unordered_map<int, GameMenu*> menus;

    //methods
    void endScene();
    virtual void declareSceneAssets() {};
    virtual void setUpScene() {};
    bool sendMessageToMenus(InputMessage* message);
    

private:
    //attributes
    
    //methods
    void init();
    void handleTextInput();
};
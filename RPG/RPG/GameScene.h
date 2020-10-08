#pragma once

class BaseGameEngine;

class GameScene
{
public:
    //attributes
    BaseGameEngine* engine;

    //constructor
    GameScene();
    GameScene(BaseGameEngine * gameEngine);

    //methods
    virtual void loadSceneAssets();
    virtual void setUpScene();
    virtual void handleInput();
    virtual void sceneLogic();
    virtual void renderScene();

};


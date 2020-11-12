#pragma once
#include "MenuButton.h"
#include "RpgWorldBuilderScene.h"

class SaveMapBuilderButton : public MenuButton
{
public:
    //attributes
    RpgWorldBuilderScene* scene;
    BaseGameEngine* engine;

    //constructors
    SaveMapBuilderButton();
    SaveMapBuilderButton(int buttonTextureKey, RpgWorldBuilderScene* gameScene);

    //methods
    void onClick();
};


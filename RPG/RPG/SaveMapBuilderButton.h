#pragma once
#include "MenuButton.h"
#include "RpgWorldBuilderScene.h"

class SaveMapBuilderButton : public MenuButton
{
public:
    //attributes
    RpgWorldBuilderScene* scene;

    //constructors
    SaveMapBuilderButton();
    SaveMapBuilderButton(int buttonTextureKey, RpgWorldBuilderScene* gameScene);

    //methods
    void onClick();
};


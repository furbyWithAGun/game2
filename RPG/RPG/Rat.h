#pragma once
#include "AiUnit.h"

class TileGridScene;

class Rat : public AiUnit
{
public:
    //attributes

    //constructors
    Rat();
    Rat(TileGridScene* gameScene);

    //methods
    void createAnimations();
};


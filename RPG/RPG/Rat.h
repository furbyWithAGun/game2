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
    Rat(TileGridScene* gameScene, int startX, int startY);

    //methods
    void createAnimations();

private:
    void init();
    void init(TileGridScene* gameScene);
};


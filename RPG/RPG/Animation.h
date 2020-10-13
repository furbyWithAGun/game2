#pragma once
#include "GameScene.h"

class Animation
{
public:
    //attributes
    GameScene * scene;
    int spriteSheetKey;
    int numFrames, frameHeight, frameWidth, ticksBetweenFrames, tickCount, currentFrame;

    //constructors
    Animation();
    Animation(GameScene * newScene, int newSpriteSheetKey, int newNumFrames, int newTicksBetweenFrames);

    //methods
    void tick();
    void resetAnimation(int startframe = 0);
};


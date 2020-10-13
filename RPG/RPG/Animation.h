#pragma once
#include "Texture.h"

class Animation
{
public:
    //attributes
    Texture * spriteSheet;
    int numFrames, frameHeight, frameWidth, animationSpeed;

    //constructors
    Animation();
    Animation(Texture* newSpriteSheet);

    //methods
    bool play();
};


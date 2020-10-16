#pragma once
#include "Sprite.h"
#include "Animation.h"

class AnimatedSprite : public Sprite
{
public:
    //attributes
    std::unordered_map<int, Animation> animations;
    Animation* currentAnimation;

    //constructors
    AnimatedSprite();
    AnimatedSprite(GameScene* gameScene);

    //methods
    void addAnimation(int animationKey, int spriteSheetKey, int numFrames, int ticksBetweenFrames, bool isLoop = true);
    void startAnimation(int animationKey);
    void init();
    virtual void update();
    void draw();
    void resize(int x , int y);
};


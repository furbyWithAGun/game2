#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : Sprite()
{
    currentAnimation = NULL;
    tempAnimation = NULL;
}

AnimatedSprite::AnimatedSprite(GameScene* gameScene) : Sprite()
{
    currentAnimation = NULL;
    tempAnimation = NULL;
    scene = gameScene;
}

void AnimatedSprite::addAnimation(int animationKey, int spriteSheetKey, int numFrames, int ticksBetweenFrames, bool isLoop)
{
    if (!animations.count(animationKey))
    {
        animations[animationKey] = Animation(scene, spriteSheetKey, numFrames, ticksBetweenFrames, isLoop);
    }
    if (currentAnimation == NULL)
    {
        init();
    }
}

void AnimatedSprite::setAnimation(int animationKey) {
    if (currentAnimation != &animations[animationKey])
    {
        currentAnimation = &animations[animationKey];
    }
}

void AnimatedSprite::playAnimation(int animationKey) {
    if (tempAnimation != &animations[animationKey])
    {
        tempAnimation = &animations[animationKey];
    }
    tempAnimation->resetAnimation();
}

void AnimatedSprite::playAnimation(int animationKey, int duration) {
    if (tempAnimation != &animations[animationKey])
    {
        tempAnimation = &animations[animationKey];
    }
    tempAnimation->setAnimationLength(duration);
    tempAnimation->resetAnimation();
}

//void AnimatedSprite::startAnimation(int animationKey)
//{
    //currentAnimation = &animations[animationKey];
    //currentAnimation->resetAnimation();
//}

void AnimatedSprite::init()
{
    currentAnimation = &animations.begin()->second;
    width = currentAnimation->frameWidth;
    height = currentAnimation->frameHeight;
    currentAnimation->resetAnimation();
}

void AnimatedSprite::update()
{
    if (tempAnimation != NULL && tempAnimation->active)
    {
        tempAnimation->tick();
    }
    currentAnimation->tick();
}

void AnimatedSprite::draw()
{
    if (tempAnimation != NULL && tempAnimation->active)
    {
        scene->engine->renderAnimation(tempAnimation, xpos, ypos, width, height);
    }
    else if (currentAnimation != NULL && currentAnimation->active) {
        scene->engine->renderAnimation(currentAnimation, xpos, ypos, width, height);
    }
}

void AnimatedSprite::resize(int x, int y) {
    width = x;
    height = y;
}
#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : Sprite()
{
    currentAnimation = NULL;
}

AnimatedSprite::AnimatedSprite(GameScene* gameScene) : Sprite()
{
    currentAnimation = NULL;
    scene = gameScene;
}

void AnimatedSprite::addAnimation(int animationKey, int spriteSheetKey, int numFrames, int ticksBetweenFrames)
{
    if (!animations.count(animationKey))
    {
        animations[animationKey] = Animation(scene, spriteSheetKey, numFrames, ticksBetweenFrames);
    }
    if (currentAnimation == NULL)
    {
        init();
    }
}

void AnimatedSprite::startAnimation(int animationKey)
{
    currentAnimation = &animations[animationKey];
    currentAnimation->resetAnimation();
    //width = currentAnimation->frameWidth;
    //height = currentAnimation->frameHeight;
}

void AnimatedSprite::init()
{
    currentAnimation = &animations.begin()->second;
    width = currentAnimation->frameWidth;
    height = currentAnimation->frameHeight;
    currentAnimation->resetAnimation();
}

void AnimatedSprite::update()
{
    printf("tick");
    currentAnimation->tick();
}

void AnimatedSprite::draw()
{
    scene->engine->renderAnimation(currentAnimation, xpos, ypos, width, height);
}

void AnimatedSprite::resize(int x, int y) {
    width = x;
    height = y;
}
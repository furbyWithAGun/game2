#include "Animation.h"

Animation::Animation()
{
    scene = NULL;
    spriteSheetKey = 0;
    numFrames = frameHeight = frameWidth = ticksBetweenFrames = 1;
    currentFrame = tickCount = 0;
    active = true;
    loop = true;
}

Animation::Animation(GameScene * newScene, int newSpriteSheetKey, int newNumFrames, int newTicksBetweenFrames)
{
    scene = newScene;
    spriteSheetKey = newSpriteSheetKey;
    numFrames = newNumFrames;
    frameHeight = newScene->textures[newSpriteSheetKey]->height / newNumFrames;
    frameWidth = newScene->textures[newSpriteSheetKey]->width;
    ticksBetweenFrames = newTicksBetweenFrames;
    currentFrame = tickCount = 0;
    active = true;
    loop = true;
}

Animation::Animation(GameScene* newScene, int newSpriteSheetKey, int newNumFrames, int newTicksBetweenFrames, bool isLoop)
{
    scene = newScene;
    spriteSheetKey = newSpriteSheetKey;
    numFrames = newNumFrames;
    frameHeight = newScene->textures[newSpriteSheetKey]->height / newNumFrames;
    frameWidth = newScene->textures[newSpriteSheetKey]->width;
    ticksBetweenFrames = newTicksBetweenFrames;
    currentFrame = tickCount = 0;
    active = isLoop;
    loop = isLoop;
}

void Animation::tick()
{
    tickCount++;
    if (tickCount >= ticksBetweenFrames)
    {
        if (currentFrame == numFrames - 1) {
            if (loop)
            {
                resetAnimation();
            } else{
                active = false;
            }
        }
        else {
            tickCount = 0;
            currentFrame++;
        }
    }
}

void Animation::resetAnimation(int startframe) {
    active = true;
    tickCount = 0;
    currentFrame = startframe;
}

void Animation::setAnimationLength(int lengthInGameTicks)
{
    ticksBetweenFrames = lengthInGameTicks / numFrames;
}

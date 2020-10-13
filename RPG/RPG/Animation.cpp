#include "Animation.h"

Animation::Animation()
{
    scene = NULL;
    spriteSheetKey = 0;
    numFrames = frameHeight = frameWidth = ticksBetweenFrames = 1;
    currentFrame = tickCount = 0;
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
}

void Animation::tick()
{
    tickCount++;
    if (tickCount >= ticksBetweenFrames)
    {
        if (currentFrame == numFrames - 1) {
            tickCount = 0;
            currentFrame = 0;
        }
        else {
            tickCount = 0;
            currentFrame++;
        }
    }
}

void Animation::resetAnimation(int startframe) {
    tickCount = 0;
    currentFrame = startframe;
}

void resize(int x, int y) {

}
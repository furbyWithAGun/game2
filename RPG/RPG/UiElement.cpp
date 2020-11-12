#include "UiElement.h"

UiElement::UiElement() : Sprite()
{
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene) : Sprite(spriteTextureKey, gameScene)
{
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(spriteTextureKey, gameScene, xpos, ypos, elementWidth, elementHeight)
{
}

UiElement::UiElement(SDL_Color spriteBackgroundColour, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(spriteBackgroundColour, gameScene, xpos, ypos, elementWidth, elementHeight)
{
}

void UiElement::draw() {
    Sprite::draw();
}

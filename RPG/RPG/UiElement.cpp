#include "UiElement.h"

const SDL_Color DEFAULT_UI_ELEMENT_COLOUR = { 0, 0, 0 };

UiElement::UiElement() : Sprite()
{
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene) : Sprite(spriteTextureKey, gameScene)
{
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos) : Sprite(spriteTextureKey, gameScene, xpos, ypos)
{
}

UiElement::UiElement(SDL_Color elementColour, GameScene* gameScene, int xpos, int ypos) : Sprite(elementColour, gameScene, xpos, ypos)
{
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(spriteTextureKey, gameScene, xpos, ypos, elementWidth, elementHeight)
{
}

UiElement::UiElement(GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(DEFAULT_UI_ELEMENT_COLOUR, gameScene, xpos, ypos, elementWidth, elementHeight)
{
}

UiElement::UiElement(SDL_Color spriteBackgroundColour, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(spriteBackgroundColour, gameScene, xpos, ypos, elementWidth, elementHeight)
{
}

void UiElement::draw() {
	if (active)
	{
		Sprite::draw();
	}
}

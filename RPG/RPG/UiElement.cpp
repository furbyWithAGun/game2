#include "UiElement.h"

const SDL_Color DEFAULT_UI_ELEMENT_COLOUR = { 0, 0, 0 };

UiElement::UiElement() : Sprite()
{
    init();
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene) : Sprite(spriteTextureKey, gameScene)
{
    init();
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos) : Sprite(spriteTextureKey, gameScene, xpos, ypos)
{
    init();
}

UiElement::UiElement(SDL_Color elementColour, GameScene* gameScene, int xpos, int ypos) : Sprite(elementColour, gameScene, xpos, ypos)
{
    init();
}

UiElement::UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(spriteTextureKey, gameScene, xpos, ypos, elementWidth, elementHeight)
{
    init();
}

UiElement::UiElement(GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(DEFAULT_UI_ELEMENT_COLOUR, gameScene, xpos, ypos, elementWidth, elementHeight)
{
    init();
}

UiElement::UiElement(SDL_Color spriteBackgroundColour, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : Sprite(spriteBackgroundColour, gameScene, xpos, ypos, elementWidth, elementHeight)
{
    init();
}

void UiElement::init() {
    text = "";
}

void UiElement::draw() {
	if (active)
	{
		Sprite::draw();
	}
}


int UiElement::addElement(int elementId, UiElement* newElement) {
    if (subElements.find(elementId) == subElements.end())
    {
        subElements[elementId] = newElement;
        return elementId;
    }
    else {
        return -1;
    }
}

UiElement* UiElement::getElementbyId(int elementId) {
    if (subElements.find(elementId) == subElements.end()) {
        return subElements[elementId];
    }
    for (auto element : subElements) {
        if (element.second->getElementbyId(elementId) != NULL)
        {
            return element.second->getElementbyId(elementId);
        }
    }
    return NULL;
}

std::string UiElement::getText(int subElementId) {
    UiElement* element = getElementbyId(subElementId);
    if (element != NULL)
    {
        return element->getText();
    }
    return "";
}

void UiElement::setText(std::string newText) {
    text = newText;
}

void UiElement::setText(int subElementId, std::string newText) {
    UiElement* element = getElementbyId(subElementId);
    if (element != NULL)
    {
        element->setText(newText);
    }
}
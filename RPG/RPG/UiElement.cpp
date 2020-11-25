#include "UiElement.h"

const SDL_Color DEFAULT_UI_ELEMENT_COLOUR = { 0, 0, 0 };

UiElement::UiElement() : Sprite()
{
    init();
}

UiElement::UiElement(GameScene* newScene, int xpos, int ypos) : Sprite(newScene, xpos, ypos)
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
    id = -1;
    text = "";
    dynamicPosition = dynamicSize = true;
    layout = FLOW_LAYOUT;
    alignment = VERTICAL;
}

void UiElement::init(int newId) {
    init();
    id = newId;
}

void UiElement::draw() {
	if (active)
	{
		Sprite::draw();
	}
}


void UiElement::addElement(UiElement* newElement) {
    subElements.push_back(newElement);
}

UiElement* UiElement::getElementbyId(int elementId) {
    if (id == elementId)
    {
        return this;
    }

    for (auto element : subElements) {
        if (element->id == elementId)
        {
            return element;
        }

        if (element->getElementbyId(elementId) != NULL)
        {
            return element->getElementbyId(elementId);
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
#include "ScrollBox.h"

const SDL_Color DEFAULT_ARROW_MORE_COLOUR = { 0, 0, 255 };
const SDL_Color DEFAULT_ARROW_END_COLOUR = { 150, 150, 150 };

ScrollBox::ScrollBox() : UiElement()
{
    init();
}

ScrollBox::ScrollBox(GameScene* gameScene, SDL_Color spriteBackgroundColour, int xpos, int ypos, int elementWidth, int elementHeight) : UiElement(gameScene, spriteBackgroundColour, xpos, ypos, elementWidth, elementHeight)
{
    init();
}

ScrollBox::ScrollBox(int elementId, GameScene* gameScene, SDL_Color spriteBackgroundColour, int xpos, int ypos, int elementWidth, int elementHeight) : UiElement(elementId, gameScene, spriteBackgroundColour, xpos, ypos, elementWidth, elementHeight)
{
    init();
}

void ScrollBox::init()
{
    numElementsToDisplay = 1;
    displayIndex = 0;
    arrowMoreColour = DEFAULT_ARROW_MORE_COLOUR;
    arrowEndColour = DEFAULT_ARROW_END_COLOUR;
    upArrowEnd = Sprite(arrowEndColour, scene, xpos + (width - scene->engine->screenWidth * 0.02) / 2, ypos, scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
    upArrowMore = Sprite(arrowMoreColour, scene, xpos + (width - scene->engine->screenWidth * 0.02) / 2, ypos, scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
    downArrowEnd = Sprite(arrowEndColour, scene, xpos + (width - scene->engine->screenWidth * 0.02) / 2, ypos + height - scene->engine->screenHeight * 0.02, scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
    downArrowMore = Sprite(arrowMoreColour, scene, xpos + (width - scene->engine->screenWidth * 0.02) / 2, ypos + height - scene->engine->screenHeight * 0.02, scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
}

void ScrollBox::addElement(UiElement* newElement)
{
    subElements.push_back(newElement);
}

bool ScrollBox::handleInput(InputMessage* message)
{
    bool messageConsumed = false;
    if (active)
    {
        for (auto element : subElements) {
            if (!messageConsumed)
            {
                messageConsumed = element->handleInput(message);
            }
        }
        if (!messageConsumed)
        {
            switch (message->id)
            {
            case SELECT_ON:
                if (displayIndex > 0 && upArrowMore.pointCollision(message->x, message->y))
                {
                    displayIndex -= 1;
                    messageConsumed = true;
                }
                else if (displayIndex + numElementsToDisplay < subElements.size() && downArrowMore.pointCollision(message->x, message->y)) {
                    displayIndex += 1;
                    messageConsumed = true;
                }
                break;
            case SCROLL_UP:
                if (displayIndex > 0 && pointCollision(message->x, message->y))
                {
                    displayIndex -= 1;
                    messageConsumed = true;
                }
                break;
            case SCROLL_DOWN:
                if (displayIndex + numElementsToDisplay < subElements.size() && pointCollision(message->x, message->y)) {
                    displayIndex += 1;
                    messageConsumed = true;
                }
                break;
            default:
                break;
            }
        }
    }
    updateElementsStatus();
    return messageConsumed;
}

void ScrollBox::draw()
{
    if (active)
    {
        UiElement::draw();
        if (subElements.size() > numElementsToDisplay)
        {
            if (displayIndex == 0)
            {
                upArrowEnd.draw();
            }
            else {
                upArrowMore.draw();
            }

            if (displayIndex + numElementsToDisplay < subElements.size())
            {
                downArrowMore.draw();
            }
            else {
                downArrowEnd.draw();
            }
        }

        for (auto [i, z] = std::tuple{ displayIndex, 1 }; i < numElementsToDisplay + displayIndex; i++, z++)
        {
            if (i < subElements.size()) {
                if (subElements[i]->width != -1 && subElements[i]->height != -1)
                {
                    subElements[i]->xpos = xpos + (width - subElements[i]->width) / 2;
                    subElements[i]->ypos = (ypos + upArrowEnd.height + z * (height / (numElementsToDisplay + 0.5)) - height * 0.3);
                }
                else {
                    subElements[i]->xpos = xpos + scene->engine->screenWidth * 0.025;
                    subElements[i]->ypos = (ypos + upArrowEnd.height + z * (height / (numElementsToDisplay + 0.5)) - height * 0.3);
                }
                subElements[i]->draw();
            }
        }
    }
}

void ScrollBox::updateElementsStatus() {
    for (size_t i = 0; i < subElements.size(); i++)
    {
        if (i <= displayIndex + numElementsToDisplay && i >= displayIndex) {
            subElements[i]->active = true;
        }
        else {
            subElements[i]->active = false;
        }
    }
}


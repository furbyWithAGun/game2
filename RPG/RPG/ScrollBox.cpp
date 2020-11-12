#include "ScrollBox.h"

const SDL_Color DEFAULT_ARROW_MORE_COLOUR = { 0, 0, 125 };
const SDL_Color DEFAULT_ARROW_END_COLOUR = { 0, 0, 255 };

ScrollBox::ScrollBox() : UiElement()
{
    init();
}

ScrollBox::ScrollBox(SDL_Color spriteBackgroundColour, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight) : UiElement(spriteBackgroundColour, gameScene, xpos, ypos, elementWidth, elementHeight)
{
    init();
}


void ScrollBox::init()
{
    numElementsToDisplay = 1;
    displayIndex = 0;
    arrowMoreColour = DEFAULT_ARROW_MORE_COLOUR;
    arrowEndColour = DEFAULT_ARROW_END_COLOUR;
    upArrowEnd = Sprite(arrowEndColour, scene, xpos + width / 2, ypos, width * scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
    upArrowMore = Sprite(arrowMoreColour, scene, xpos + width / 2, ypos, width * scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
    downArrowEnd = Sprite(arrowEndColour, scene, xpos + width / 2, ypos + height - scene->engine->screenHeight * 0.02, width * scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
    downArrowMore = Sprite(arrowMoreColour, scene, xpos + width / 2, ypos + height - scene->engine->screenHeight * 0.02, width * scene->engine->screenWidth * 0.02, scene->engine->screenHeight * 0.02);
}

void ScrollBox::addElement(UiElement* newElement)
{
    subElements.push_back(newElement);
}

bool ScrollBox::handleInput(InputMessage* message)
{
    bool messageConsumed = false;
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
    
    return messageConsumed;
}

void ScrollBox::draw()
{
    UiElement::draw();
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
    int z = 0;
    for (size_t i = displayIndex; i < numElementsToDisplay + displayIndex; i++)
    {
        z += 1;
        if (i < subElements.size()) {
            subElements[i]->xpos = xpos + scene->engine->screenWidth * 0.01;
            subElements[i]->ypos = ypos + upArrowEnd.height + z * (height / (numElementsToDisplay + 2));
            subElements[i]->draw();
        }
    }
    
}


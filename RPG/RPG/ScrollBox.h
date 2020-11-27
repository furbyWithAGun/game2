#pragma once
#include "UiElement.h"
class ScrollBox : public UiElement
{
public:
    //attributes
    //std::vector<UiElement*> subElements;
    SDL_Colour arrowMoreColour;
    SDL_Colour arrowEndColour;
    Sprite upArrowMore;
    Sprite upArrowEnd;
    Sprite downArrowMore;
    Sprite downArrowEnd;

    //constructors
    ScrollBox();
    ScrollBox(GameScene* gameScene, SDL_Color spriteBackgroundColour, int xpos, int ypos, int elementWidth, int elementHeight);
    ScrollBox(int elementId, GameScene* gameScene, SDL_Color spriteBackgroundColour, int xpos, int ypos, int elementWidth, int elementHeight);

    //methods
    void addElement(UiElement* newElement);
    bool handleInput(InputMessage* message) override;
    void draw() override;

private:
    void init();
    void updateElementsStatus();
};


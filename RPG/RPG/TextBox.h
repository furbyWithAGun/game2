#pragma once
#include "UiElement.h"

class TextBox : public UiElement
{
public:
    //attributes
    SDL_Color textColour;
    int numCharsToDisplay;
    bool gettingText;

    //constructors
    TextBox();
    TextBox(GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);
    TextBox(int elementId, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);

    //methods
    void draw() override;
    bool handleInput(InputMessage* message) override;

private:
    //methods
    void init();
};


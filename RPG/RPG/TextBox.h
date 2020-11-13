#pragma once
#include "UiElement.h"

class TextBox : public UiElement
{
public:
    //attributes
    std::string text;
    SDL_Color textColour;
    int numCharsToDisplay;
    bool gettingText;

    //constructors
    TextBox();
    TextBox(GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);

    //methods
    void draw() override;
    bool handleInput(InputMessage* message) override;

private:
    //methods
    void init();
};


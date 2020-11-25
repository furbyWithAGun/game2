#include "MenuText.h"
#include "BaseGameEngine.h"

MenuText::MenuText()
{
    init();
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos) : UiElement(newScene, xpos, ypos) {
    init(newText);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos): UiElement(textColour, newScene, xpos, ypos)
{
    init(newText);
    colour = textColour;
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight) : UiElement(SDL_Color {0, 0, 0}, newScene, xpos, ypos, newWidth, newHeight)
{
    init(newText);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight) : UiElement(textColour, newScene, xpos, ypos, newWidth, newHeight)
{
    init(newText);
    colour = textColour;
}

void MenuText::init() {
    colour = { 0, 0, 0 };
}

void MenuText::init(std::string newText) {
    init();
    text = newText;
}

void MenuText::setPos(int newX, int newY)
{
    xpos = newX;
    ypos = newY;
}

void MenuText::draw()
{
    if (active)
    {
        UiElement::draw();
        if (width != -1 && height != -1)
        {
            scene->engine->renderText(text, xpos, ypos, width, height, colour);
        }
        else {
            scene->engine->renderText(text, xpos, ypos, colour);
        }
    }
}
#include "MenuText.h"
#include "BaseGameEngine.h"

MenuText::MenuText()
{
    init();
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos) : UiElement(newScene, xpos, ypos) {
    init(newText);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos): UiElement(newScene, textColour, xpos, ypos)
{
    init(newText);
    colour = textColour;
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight) : UiElement(newScene, SDL_Color {0, 0, 0},xpos, ypos, newWidth, newHeight)
{
    init(newText);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight) : UiElement(newScene, textColour, xpos, ypos, newWidth, newHeight)
{
    init(newText);
    colour = textColour;
}

MenuText::MenuText(int elementId, GameScene* newScene, std::string newText, int xpos, int ypos) : UiElement(elementId, newScene, xpos, ypos) {
    init(newText);
}

MenuText::MenuText(int elementId, GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos) : UiElement(elementId, newScene, textColour, xpos, ypos)
{
    init(newText);
    colour = textColour;
}

MenuText::MenuText(int elementId, GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight) : UiElement(elementId, newScene, SDL_Color{ 0, 0, 0 }, xpos, ypos, newWidth, newHeight)
{
    init(newText);
}

MenuText::MenuText(int elementId, GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight) : UiElement(elementId, newScene, textColour, xpos, ypos, newWidth, newHeight)
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
#include "MenuText.h"
#include "BaseGameEngine.h"

MenuText::MenuText()
{
    init();
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos) : UiElement() {
    init(newScene, newText);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos): UiElement(textColour, newScene, xpos, ypos)
{
    init(newScene, newText);
    colour = textColour;
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight) : UiElement(SDL_Color {0, 0, 0}, newScene, xpos, ypos, newWidth, newHeight)
{
    init(newScene, newText);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight) : UiElement(textColour, newScene, xpos, ypos, newWidth, newHeight)
{
    init(newScene, newText);
    colour = textColour;
}

void MenuText::init() {
    scene = NULL;
    colour = { 0, 0, 0 };
}

void MenuText::init(GameScene* newScene, std::string newText) {
    init();
    scene = newScene;
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
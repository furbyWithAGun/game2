#include "MenuText.h"
#include "BaseGameEngine.h"

MenuText::MenuText()
{
    init();
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos) {
    init(newScene, newText, xpos, ypos);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos)
{
    init(newScene, newText, xpos, ypos);
    colour = textColour;
}

MenuText::MenuText(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight)
{
    init(newScene, newText, xpos, ypos, newWidth, newHeight);
}

MenuText::MenuText(GameScene* newScene, std::string newText, SDL_Color textColour, int xpos, int ypos, int newWidth, int newHeight)
{
    init(newScene, newText, xpos, ypos, newWidth, newHeight);
    colour = textColour;
}

void MenuText::init() {
    scene = NULL;
    text = "";
    colour = { 0, 0, 0 };
    x = y = width = height = -1;
}

void MenuText::init(GameScene* newScene, std::string newText, int xpos, int ypos) {
    init();
    scene = newScene;
    text = newText;
    x = xpos;
    y = ypos;
}

void MenuText::init(GameScene* newScene, std::string newText, int xpos, int ypos, int newWidth, int newHeight) {
    init(newScene, newText, xpos, ypos);
    width = newWidth;
    height = newHeight;
}

void MenuText::setText(std::string newText)
{
    text = newText;
}

void MenuText::setPos(int newX, int newY)
{
    x = newX;
    y = newY;
}

void MenuText::draw()
{
    if (width != -1 && height != -1)
    {
        scene->engine->renderText(text, x, y, width, height, colour);
    }
    else {
        scene->engine->renderText(text, x, y, colour);
    }
}
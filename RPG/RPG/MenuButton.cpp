#include "MenuButton.h"

MenuButton::MenuButton(Texture spriteTexture, BaseGameEngine * gameEngine) : Sprite(spriteTexture, gameEngine){
    engine = gameEngine;
    text = "";
    textXoffset = textYoffset = 0;
}

MenuButton::MenuButton() : Sprite() {
    engine = NULL;
    text = "";
    textXoffset = textYoffset = 0;
}

MenuButton::~MenuButton() {
    engine = NULL;
    delete &textTexture;
    text = "";
    textXoffset = textYoffset = 0;
}

void MenuButton::draw() {
    Sprite::draw();
    if (!textTexture.texture == NULL)
    {
        engine->renderTexture(textTexture, xpos + textXoffset, ypos + textYoffset);
    }
}

void MenuButton::setText(std::string newText) {
    text = newText;
    textTexture.texture = engine->loadTextureFromText(newText);
    SDL_QueryTexture(textTexture.texture, NULL, NULL, &textTexture.width, &textTexture.height);
}

void MenuButton::setPos(int x, int y) {

}
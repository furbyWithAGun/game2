#include "MenuButton.h"

MenuButton::MenuButton(Texture spriteTexture, BaseGameEngine * gameEngine) : Sprite(spriteTexture, gameEngine){
    engine = gameEngine;
}

MenuButton::MenuButton() : Sprite() {
    engine = NULL;
    text = "";
}

void MenuButton::draw() {
    if (!textTexture.texture == NULL)
    {
        engine->renderTexture(textTexture, xpos, ypos);
    }
    Sprite::draw();
}

void MenuButton::setText(std::string newText) {
    text = newText;
    textTexture.texture = engine->loadTextureFromText(newText);
    SDL_QueryTexture(textTexture.texture, NULL, NULL, &textTexture.width, &textTexture.height);
}
#include "MenuButton.h"

MenuButton::MenuButton(Texture spriteTexture, BaseGameEngine * gameEngine) {
    engine = gameEngine;
    texture = spriteTexture;
    width = texture.width;
    height = texture.height;
    xpos = 0;
    ypos = 0;
}

MenuButton::MenuButton() {
    width = texture.width;
    height = texture.height;
}

void MenuButton::onClick() {

}

void MenuButton::draw() {

}
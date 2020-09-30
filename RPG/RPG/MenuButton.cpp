#include "MenuButton.h"

MenuButton::MenuButton(Texture spriteTexture, BaseGameEngine * gameEngine) : Sprite(spriteTexture, gameEngine){
    engine = gameEngine;
}

MenuButton::MenuButton() : Sprite() {
    engine = NULL;
}

#include "MenuButton.h"

MenuButton::MenuButton() : UiElement() {
    init();
}

MenuButton::MenuButton(GameScene* gameScene, int spriteTextureKey) : UiElement(gameScene, spriteTextureKey){
    init();
    scene = gameScene;
}

MenuButton::MenuButton(int elementId, GameScene* gameScene, int spriteTextureKey) : UiElement(elementId, gameScene, spriteTextureKey) {
    init();
    scene = gameScene;
}

void MenuButton::init() {
    scene = NULL;
    text = "";
    textXoffset = textYoffset = textWidth = textHeight = 0;
    textTextureKey = -1;
}

//public methods
bool MenuButton::handleInput(InputMessage* message) {
    bool messageConsumed = false;
    if (active)
    {
        if (message->id == SELECT_ON && pointCollision(message->x, message->y))
        {
            messageConsumed = true;
            onClick();
        }
    }
    return messageConsumed;
}

void MenuButton::draw() {
    if (active)
    {
        UiElement::draw();
        if (!textTextureKey != -1)
        {
            scene->renderTexture(textTextureKey, xpos + textXoffset, ypos + textYoffset, textWidth, textHeight);
        }
    }
}

void MenuButton::setText(std::string newText) {
    text = newText;
    textTextureKey = scene->engine->createTextTexture(newText);
    textHeight = height * 0.75;
    textWidth = width * 0.75;
    textXoffset = width * 0.09;
    textYoffset = height * 0.11;
}

void MenuButton::setPos(int x, int y) {

}
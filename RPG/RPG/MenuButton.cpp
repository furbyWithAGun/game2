#include "MenuButton.h"

MenuButton::MenuButton() : Sprite() {
    init();
}

MenuButton::MenuButton(Texture * spriteTexture, GameScene* gameScene) : Sprite(spriteTexture, gameScene){
    init();
    scene = gameScene;
}

void MenuButton::init() {
    scene = NULL;
    text = "";
    textXoffset = textYoffset = textWidth = textHeight = 0;
    textTextureKey = -1;
}

//MenuButton::~MenuButton() {
//    scene = NULL;
//    text = "";
//    textXoffset = textYoffset = 0;
//}

void MenuButton::draw() {
    Sprite::draw();
    if (!textTextureKey != -1)
    {
        scene->renderTexture(textTextureKey, xpos + textXoffset, ypos + textYoffset, textWidth, textHeight);
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
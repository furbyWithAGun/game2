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
    textXoffset = textYoffset = 0;
}

MenuButton::~MenuButton() {
    scene = NULL;
    delete &textTexture;
    text = "";
    textXoffset = textYoffset = 0;
}

void MenuButton::draw() {
    Sprite::draw();
    if (!textTexture.texture == NULL)
    {
        scene->renderTexture(&textTexture, xpos + textXoffset, ypos + textYoffset);
    }
}

void MenuButton::setText(std::string newText) {
    text = newText;
    textTexture.texture = scene->engine->loadTextureFromText(newText);
    SDL_QueryTexture(textTexture.texture, NULL, NULL, &textTexture.width, &textTexture.height);
}

void MenuButton::setPos(int x, int y) {

}
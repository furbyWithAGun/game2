#pragma once
#include "InputMessage.h"
#include "Sprite.h"

class UiElement : public Sprite
{
public:
    //attributes
    std::unordered_map<int, UiElement*> subElements;
    std::string text;

    //constructors
    UiElement();
    UiElement(int spriteTextureKey, GameScene* gameScene);
    UiElement(SDL_Color elementColour, GameScene* gameScene, int xpos, int ypos);
    UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos);
    UiElement(int spriteTextureKey, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);
    UiElement(GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);
    UiElement(SDL_Color spriteBackgroundColour, GameScene* gameScene, int xpos, int ypos, int elementWidth, int elementHeight);

    //methods
    virtual void draw();
    virtual bool handleInput(InputMessage* message) { return false; };
    virtual std::string getText() { return text; };
    virtual std::string getText(int subElementId);
    virtual void setText(std::string newText);
    virtual void setText(int subElementId, std::string newText);
    int addElement(int elementId, UiElement* element);
    UiElement* getElementbyId(int elementId);

private:
    void init();
};


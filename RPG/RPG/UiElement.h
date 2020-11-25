#pragma once
#include "InputMessage.h"
#include "Sprite.h"

enum LAYOUTS {
    FLOW_LAYOUT,
    SINGLE_LINE
};

enum ALIGNMENTS
{
    VERTICAL,
    HORIZONTAL
};

const int ALL_ELEMENTS = -1;

class UiElement : public Sprite
{
public:
    //attributes
    int id;
    std::vector<UiElement*> subElements;
    std::string text;
    bool dynamicPosition, dynamicSize;
    int layout, alignment;
    int numElementsToDisplay;
    int displayIndex;

    //constructors
    UiElement();
    UiElement(GameScene* newScene, int xpos, int ypos);
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
    void addElement(UiElement* element);
    UiElement* getElementbyId(int elementId);

private:
    void init();
    void init(int newId);
};


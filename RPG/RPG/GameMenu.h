#pragma once
#include <vector>
#include <unordered_map>

class MenuButton;
class MenuText;
class BaseGameEngine;
class InputMessage;
class UiElement;

class GameMenu
{
public:
    //attributes
    std::vector<MenuButton*> buttons;
    std::unordered_map<int, UiElement*> elements;
    std::vector<MenuText*> texts;
    bool isActive;
    
    //constructors
    GameMenu();
    GameMenu(BaseGameEngine* gameEngine, int newId, int newWidth, int newHeight, int newXPos, int newYPos);

    //destructor
    ~GameMenu();

    //methods
    void setRGBA(int newR, int newG, int newB, int newA);
    int addElement(UiElement* element);
    int addElement(int elementId, UiElement* element);
    UiElement* getElementbyId(int elementId);
    int getNextElementId();
    virtual void open();
    virtual void close();
    virtual void draw();
    virtual bool handleInput(InputMessage* message);

protected:
    //attributes
    BaseGameEngine* engine;
    int width;
    int height;
    int xpos;
    int ypos;
    int id, r, g, b, a;

private:
    //attributes
    int nextElementId;

    //methods
    void init();
};


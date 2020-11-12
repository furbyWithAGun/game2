#pragma once
#include <vector>


class MenuButton;
class MenuText;
class BaseGameEngine;
class InputMessage;

class GameMenu
{
public:
    //attributes
    std::vector<MenuButton*> buttons;
    std::vector<MenuText*> texts;
    bool isActive;
    
    //constructors
    GameMenu();
    GameMenu(BaseGameEngine* gameEngine, int newId, int newWidth, int newHeight, int newXPos, int newYPos);

    //destructor
    ~GameMenu();

    //methods
    void setRGBA(int newR, int newG, int newB, int newA);
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
    //methods
    void init();
};


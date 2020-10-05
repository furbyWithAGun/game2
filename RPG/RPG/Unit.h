#pragma once
#include "Sprite.h"

//class RpgGameEngine;

enum MOVEMENT {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};

class Unit : public Sprite
{
public:
    //attributes
    BaseGameEngine* engine;
    std::vector<int> tileLocation;
    std::vector<int> tileDestination;
    std::string name;
    int health;
    int speed;
    double leftToMove;

    //constructors
    Unit();
    Unit(Texture * spriteTexture, BaseGameEngine* gameEngine);

    //destructor
    ~Unit();

    //methods
    void startMovement(int direction);
    void updateMovement();
    //void draw();
};


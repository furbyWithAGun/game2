#pragma once
#include "Sprite.h"
#include "RpgGameConstants.h"
#include "TileGridScene.h"

class BaseGameEngine;



class Unit : public Sprite
{
public:
    //attributes
    TileGridScene* scene;
    std::vector<int> tileLocation;
    std::vector<int> tileDestination;
    std::string name;
    int health;
    int speed;
    double leftToMove;
    bool isStatic;
    //constructors
    Unit();
    Unit(Texture * spriteTexture, TileGridScene* gameScene);

    //destructor
    ~Unit();

    //methods
    void startMovement(int direction);
    void updateMovement();
    void setTileLocation(int x, int y);
    void updateCoords();
    //void draw();
};


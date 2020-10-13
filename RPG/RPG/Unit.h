#pragma once
#include "AnimatedSprite.h"
#include "RpgGameConstants.h"
#include "TileGridScene.h"

class BaseGameEngine;



class Unit : public AnimatedSprite
{
public:
    //attributes
    TileGridScene* scene;
    std::vector<int> tileLocation;
    std::vector<int> tileDestination;
    std::string name;
    double leftToMove;
    bool isStatic;
    int directionFacing;

    //character stats
    int health;
    int speed;
    int dex;
    int str;
    int agi;

    //constructors
    Unit();
    Unit(Texture * spriteTexture, TileGridScene* gameScene);
    Unit(TileGridScene* gameScene);

    //destructor
    ~Unit();

    //methods
    void startMovement(int direction);
    void updateMovement();
    void setTileLocation(int x, int y);
    void updateCoords();
    void setStartLocation(int x, int y);
    void draw();
    void attack();
};


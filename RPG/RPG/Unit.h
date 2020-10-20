#pragma once
#include "AnimatedSprite.h"
#include "RpgGameConstants.h"
#include "TileGridScene.h"
#include "Attack.h"


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
    bool isStatic, isPlayerControlled;
    bool movingUp, movingDown, movingRight, movingLeft;
    int directionFacing;
    Animation * mainAttackAnimation;

    //character stats
    int maxHealth;
    int health;
    int speed;
    int dex;
    int str;
    int agi;
    int end;
    int intl;

    //actions
    Attack* mainAttack;


    //constructors
    Unit();
    Unit(Texture * spriteTexture, TileGridScene* gameScene);
    Unit(TileGridScene* gameScene);
    Unit(TileGridScene* gameScene, int startX, int startY);

    //destructor
    ~Unit();

    //methods
    void startMovement(int direction);
    void updateMovement();
    void setTileLocation(int x, int y);
    void updateCoords();
    void setStartLocation(int x, int y);
    
    void updateAnimation();
    virtual void createAnimations() {};
    bool isMoving();
    void draw();
    virtual void update();
    void performMainAttack();
    int assignDamage(int damageTaken);
    int getUnitState();
};


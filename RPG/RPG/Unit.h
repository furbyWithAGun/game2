#pragma once
#include "AnimatedSprite.h"
#include "RpgGameConstants.h"
#include "TileGridScene.h"
#include "Attack.h"
#include "UnitState.h"
#include "IdleState.h"
#include "MovingState.h"
#include "AttackingState.h"


class BaseGameEngine;
class InputMessage;

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
    bool attacking;
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
    Unit(TileGridScene* gameScene);
    Unit(TileGridScene* gameScene, int startX, int startY);

    //destructor
    ~Unit();

    //methods
    void startMovement(int direction);
    bool updateMovement();
    void setTileLocation(int x, int y);
    void updateCoords();
    void setStartLocation(int x, int y);
    void updateAnimation();
    virtual void createAnimations() {};
    bool isMoving();
    void draw();
    virtual void update();
    bool performMainAttack();
    int assignDamage(int damageTaken);
    void getLocationUnitIsFacing(int tileXY[2]);
    void drawHealth();
    void handleInput(InputMessage* message);

protected:
    void setUnitState(int newState);

private:
    //attributes
    UnitState* currentState;
    std::unordered_map<int, UnitState*> unitStates;

    //methods
    void init();
    void init(TileGridScene* gameScene);
};
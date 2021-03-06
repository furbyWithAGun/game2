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
    int type;
    TileGridScene* scene;
    std::vector<int> tileLocation;
    std::vector<int> tileDestination;
    std::string name;
    double leftToMove;
    bool isStatic, isPlayerControlled;
    bool movingUp, movingDown, movingRight, movingLeft;
    int directionFacing;
    //Animation * mainAttackAnimation;

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
    std::unordered_map<int, Attack*> equipedAttacks;
    Attack* activeAttack;


    //constructors
    Unit();
    Unit(int unitType);
    Unit(int unitType, TileGridScene* gameScene);
    Unit(int unitType, TileGridScene* gameScene, int startX, int startY);

    //destructor
    ~Unit();

    //methods
    void startMovement(int direction);
    bool updateMovement();
    void setTileLocation(int x, int y);
    void updateCoords();
    void setStartLocation(int x, int y);
    virtual void createAnimations() {};
    void draw();
    virtual void update();
    bool performAttack(int attackId);
    int assignDamage(int damageTaken);
    void getLocationUnitIsFacing(int tileXY[2]);
    void drawHealth();
    void handleInput(InputMessage* message);
    void updateAttacks();
    void faceCoords(int x, int y);

protected:
    void setUnitState(int newState);

private:
    //attributes
    UnitState* currentState;
    std::unordered_map<int, UnitState*> unitStates;

    //methods
    void init();
    void init(int unitType);
    void init(int unitType, TileGridScene* gameScene);
};
#include "Unit.h"
#include"GameScene.h"


//constructors
Unit::Unit() : AnimatedSprite() {
    init();
}

Unit::Unit(TileGridScene* gameScene) : AnimatedSprite(gameScene) {
    init(gameScene);
}

Unit::Unit(TileGridScene* gameScene, int startX, int startY) : AnimatedSprite(gameScene) {
    init(gameScene);
    setStartLocation(startX, startY);
}

void Unit::init() {
    name = "";
    tileLocation = { 0, 0 };
    tileDestination = { 0, 0 };
    maxHealth = 1;
    health = 1;
    speed = 1;
    leftToMove = 0;
    isStatic = false;
    isPlayerControlled = false;
    directionFacing = DOWN;
    movingUp = movingDown = movingRight = movingLeft = false;
    setTileLocation(0, 0);
    unitStates.clear();
    unitStates.insert({ UNIT_IDLE, new IdleState(UNIT_IDLE, this) });
    unitStates.insert({ UNIT_MOVING, new MovingState(UNIT_MOVING, this) });
    unitStates.insert({ UNIT_ATTACKING, new AttackingState(UNIT_ATTACKING, this) });
    setUnitState(UNIT_IDLE);
}

void Unit::init(TileGridScene* gameScene) {
    init();
    scene = gameScene;
}

//destructor
Unit::~Unit() {
    //&tileLocation;
    //&tileDestination;
    name = "";
    health = 0;
    speed = 0;
    leftToMove = 0;
}

void Unit::startMovement(int direction) {
    leftToMove = 1;
    directionFacing = direction;

    switch (direction)
    {
    case UP:
        if (scene->isTilePassable(tileLocation[0], tileLocation[1] - 1))
        {
            tileDestination[1] = tileLocation[1] - 1;
        }
        break;
    case DOWN:
        if (scene->isTilePassable(tileLocation[0], tileLocation[1] + 1))
        {
            tileDestination[1] = tileLocation[1] + 1;
        }            
        break;
    case RIGHT:
        if (scene->isTilePassable(tileLocation[0] + 1, tileLocation[1]))
        {
            tileDestination[0] = tileLocation[0] + 1;
        }
        break;
    case LEFT:
        if (scene->isTilePassable(tileLocation[0] - 1, tileLocation[1]))
        {
            tileDestination[0] = tileLocation[0] - 1;
        }
        break;
    default:
        break;
    }
}

void Unit::update() {
    AnimatedSprite::update();
    setUnitState(currentState->update());
}

bool Unit::updateMovement() {
    //return true if unit still moving, else, return false
    if (leftToMove > 0) {
        leftToMove = leftToMove - (double)speed / 100;
    }
    if (leftToMove <= 0) {
        leftToMove = 0;
        if (tileDestination[0] != tileLocation[0] || tileDestination[1] != tileLocation[1]) {
            setTileLocation(tileDestination[0], tileDestination[1]);
        }
        if (movingUp && !movingDown) {
            startMovement(UP);
            return true;
        }
        if (movingDown && !movingUp) {
            startMovement(DOWN);
            return true;
        }
        if (movingRight && !movingLeft) {
            startMovement(RIGHT);
            return true;
        }
        if (movingLeft && !movingRight) {
            startMovement(LEFT);
            return true;
        }
        return false;
    }
    return true;
}

void Unit::setTileLocation(int x, int y) {
    tileLocation[0] = x;
    tileLocation[1] = y;
    tileDestination[0] = x;
    tileDestination[1] = y;
}

void Unit::updateCoords() {
    int coords[2];
    int destCoords[2];
    scene->coordsFromTileIndex(tileLocation[0], tileLocation[1], coords);
    scene->coordsFromTileIndex(tileDestination[0], tileDestination[1], destCoords);
    xpos = coords[0] + (destCoords[0] - coords[0]) * (1 - leftToMove);
    ypos = coords[1] + (destCoords[1] - coords[1]) * (1 - leftToMove);
}

void Unit::setStartLocation(int x, int y) {
    tileLocation[0] = x;
    tileLocation[1] = y;
    tileDestination[0] = x;
    tileDestination[1] = y;
    int screenCoords[2];
    scene->coordsFromTileIndex(x, y, screenCoords);
    xpos = screenCoords[0];
    ypos = screenCoords[1];
}

void Unit::draw()
{
    AnimatedSprite::draw();
    drawHealth();
}

bool Unit::performAttack(int attackId) {
    activeAttack = equipedAttacks[attackId];
    return activeAttack->startAttack();
}

int Unit::assignDamage(int damageTaken) {
    health -= damageTaken;
    if (health <= 0)
    {
        active = false;
        return health;
    }
}

void Unit::getLocationUnitIsFacing(int tileXY[2]) {
    switch (directionFacing)
    {
    case UP_LEFT:
        tileXY[0] = tileLocation[0] -1;
        tileXY[1] = tileLocation[1] - 1;
        break;
    case UP:
        tileXY[0] = tileLocation[0];
        tileXY[1] = tileLocation[1] - 1;
        break;
    case UP_RIGHT:
        tileXY[0] = tileLocation[0] + 1;
        tileXY[1] = tileLocation[1] - 1;
        break;
    case RIGHT:
        tileXY[0] = tileLocation[0] + 1;
        tileXY[1] = tileLocation[1];
        break;
    case DOWN_RIGHT:
        tileXY[0] = tileLocation[0] + 1;
        tileXY[1] = tileLocation[1] + 1;
        break;
    case DOWN:
        tileXY[0] = tileLocation[0];
        tileXY[1] = tileLocation[1] + 1;
        break;
    case DOWN_LEFT:
        tileXY[0] = tileLocation[0] - 1;
        tileXY[1] = tileLocation[1] + 1;
        break;
    case LEFT:
        tileXY[0] = tileLocation[0] - 1;
        tileXY[1] = tileLocation[1];
        break;
    default:
        tileXY[0] = tileLocation[0];
        tileXY[1] = tileLocation[1];
        break;
    }
    tileXY;
}

void Unit::drawHealth()
{
    double healthPercent = (double)health / (double)maxHealth;
    scene->engine->renderRectangle(xpos, ypos, (double)scene->tileWidth * healthPercent, (double)scene->tileHeight * 0.05, 0xff, 0, 0);
}

void Unit::handleInput(InputMessage* message) {
    setUnitState(currentState->handleInput(message));
}
void Unit::setUnitState(int newState) {
    currentState = unitStates[newState];
}

void Unit::updateAttacks() {
    for (auto attack : equipedAttacks)
    {
        attack.second->update();
    }
}

void Unit::faceCoords(int x, int y) {
    if (x < xpos && y < ypos)
    {
        directionFacing = UP_LEFT;
    }
    else if (x >= xpos && x <= xpos + width && y < ypos) {
        directionFacing = UP;
    }
    else if (x > xpos + width && y < ypos) {
        directionFacing = UP_RIGHT;
    }
    else if (x > xpos + width && y > ypos && y < ypos + height) {
        directionFacing = RIGHT;
    }
    else if (x > xpos + width && y > ypos + height) {
        directionFacing = DOWN_RIGHT;
    }
    else if (x >= xpos && x <= xpos + width && y > ypos + height) {
        directionFacing = DOWN;
    }
    else if (x < xpos && y > ypos + height) {
        directionFacing = DOWN_LEFT;
    }
    else if (x < xpos && y > ypos && y < ypos + height) {
        directionFacing = LEFT;
    }
}
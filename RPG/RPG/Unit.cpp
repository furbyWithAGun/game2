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
    attacking = false;
    movingUp = movingDown = movingRight = movingLeft = false;
    setTileLocation(0, 0);
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
    if (leftToMove == 0 && !attacking)
    {
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
}

void Unit::update() {
    AnimatedSprite::update();
    currentState->update();
    updateMovement();
    if (!isStatic) {
        updateCoords();
    }
    updateAnimation();
    mainAttack->update();
}

void Unit::updateMovement() {
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
        }
        if (movingDown && !movingUp) {
            startMovement(DOWN);
        }
        if (movingRight && !movingLeft) {
            startMovement(RIGHT);
        }
        if (movingLeft && !movingRight) {
            startMovement(LEFT);
        }
    }

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

void Unit::updateAnimation() {
    setAnimation(getUnitState());
}

bool Unit::isMoving() {
    return leftToMove != 0 || movingDown || movingUp || movingRight || movingLeft;
}

void Unit::draw()
{
    AnimatedSprite::draw();
    drawHealth();
}

void Unit::performMainAttack() {
    if (freeToAct())
    {
        mainAttack->startAttack();
    }
}

int Unit::assignDamage(int damageTaken) {
    health -= damageTaken;
    if (health <= 0)
    {
        active = false;
        return health;
    }
}

int Unit::getUnitState() {
    if (isMoving())
    {
        switch (directionFacing) {
        case UP:
            return MOVE_UP;
            break;
        case DOWN:
            return MOVE_DOWN;
            break;
        case RIGHT:
            return MOVE_RIGHT;
            break;
        case LEFT:
            return MOVE_LEFT;
            break;
        default:
            return MOVE_DOWN;
            break;
        }
    }
    else {
        switch (directionFacing) {
        case UP_LEFT:
            return IDLE_UP_LEFT;
            break;
        case UP:
            return IDLE_UP;
            break;
        case UP_RIGHT:
            return IDLE_UP_RIGHT;
            break;
        case RIGHT:
            return IDLE_RIGHT;
            break;
        case DOWN_RIGHT:
            return IDLE_DOWN_RIGHT;
            break;
        case DOWN:
            return IDLE_DOWN;
            break;
        case DOWN_LEFT:
            return IDLE_DOWN_LEFT;
            break;
        case LEFT:
            return IDLE_LEFT;
            break;
        default:
            return IDLE_DOWN;
            break;
        }
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

bool Unit::freeToAct() {
    return !isMoving() && !attacking;
}

void Unit::setUnitState(int newState) {
    currentState = &unitStates[newState];
}
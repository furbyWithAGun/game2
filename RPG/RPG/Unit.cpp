#include "Unit.h"
#include"GameScene.h"


//constructors
Unit::Unit() : AnimatedSprite() {
    tileLocation = {0, 0};
    tileDestination = {0, 0};
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    isStatic = false;
    isPlayerControlled = false;
    directionFacing = DOWN;
}

Unit::Unit(Texture * spriteTexture, TileGridScene* gameScene) : AnimatedSprite(gameScene) {
    scene = gameScene;
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    tileLocation = {0, 0};
    tileDestination = { 0, 0 };
    setTileLocation(0, 0);
    isStatic = false;
    isPlayerControlled = false;
    directionFacing = DOWN;
    movingUp = movingDown = movingRight = movingLeft = false;
}

Unit::Unit(TileGridScene* gameScene) : AnimatedSprite(gameScene) {
    scene = gameScene;
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    tileLocation = {0, 0};
    tileDestination = { 0, 0 };
    setTileLocation(0, 0);
    isStatic = false;
    isPlayerControlled = false;
    directionFacing = DOWN;
    movingUp = movingDown = movingRight = movingLeft = false;
}

Unit::Unit(TileGridScene* gameScene, int startX, int startY) : AnimatedSprite(gameScene) {
    scene = gameScene;
    name = "";
    health = 1;
    speed = 1;
    leftToMove = 0;
    tileLocation = { 0, 0 };
    tileDestination = { 0, 0 };
    setStartLocation(startX, startY);
    isStatic = false;
    isPlayerControlled = false;
    directionFacing = DOWN;
    movingUp = movingDown = movingRight = movingLeft = false;
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
    if (leftToMove == 0)
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
    if (tempAnimation != NULL && tempAnimation->active)
    {
        tempAnimation->tick();
    }

    setAnimation(getUnitState());
}

bool Unit::isMoving() {
    return leftToMove != 0 || movingDown || movingUp || movingRight || movingLeft;
}

void Unit::draw()
{
    AnimatedSprite::draw();
}

void Unit::performMainAttack() {
    Unit* targetUnit;
    switch (directionFacing)
    {
    case UP_LEFT:
        playAnimation(ATTACK_UP_LEFT);
        targetUnit = scene->getUnitAtLocation(tileLocation[0] - 1, tileLocation[1] - 1);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    case UP:
        playAnimation(ATTACK_UP);
        targetUnit = scene->getUnitAtLocation(tileLocation[0], tileLocation[1] - 1);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    case UP_RIGHT:
        playAnimation(ATTACK_UP_RIGHT);
        targetUnit = scene->getUnitAtLocation(tileLocation[0] + 1, tileLocation[1] - 1);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    case RIGHT:
        playAnimation(ATTACK_RIGHT);
        targetUnit = scene->getUnitAtLocation(tileLocation[0] + 1, tileLocation[1]);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    case DOWN_RIGHT:
        playAnimation(ATTACK_DOWN_RIGHT);
        targetUnit = scene->getUnitAtLocation(tileLocation[0] + 1, tileLocation[1] + 1);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    case DOWN:
        playAnimation(ATTACK_DOWN);
        targetUnit = scene->getUnitAtLocation(tileLocation[0], tileLocation[1] + 1);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    case DOWN_LEFT:
        playAnimation(ATTACK_DOWN_LEFT);
        targetUnit = scene->getUnitAtLocation(tileLocation[0] - 1, tileLocation[1] + 1);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    case LEFT:
        playAnimation(ATTACK_LEFT);
        targetUnit = scene->getUnitAtLocation(tileLocation[0] - 1, tileLocation[1]);
        if (targetUnit != NULL and targetUnit != this) {
            mainAttack->processHit(targetUnit);
        }
        break;
    default:
        break;
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
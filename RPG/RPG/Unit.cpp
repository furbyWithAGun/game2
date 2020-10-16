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
    animations[ATTACK_UP_LEFT].tick();
    animations[ATTACK_UP].tick();
    animations[ATTACK_UP_RIGHT].tick();
    animations[ATTACK_RIGHT].tick();
    animations[ATTACK_DOWN_RIGHT].tick();
    animations[ATTACK_DOWN].tick();
    animations[ATTACK_DOWN_LEFT].tick();
    animations[ATTACK_LEFT].tick();
    if (isMoving())
    {
        switch (directionFacing) {
        case UP:
            setAnimation(MOVE_UP);
            break;
        case DOWN:
            setAnimation(MOVE_DOWN);
            break;
        case RIGHT:
            setAnimation(MOVE_RIGHT);
            break;
        case LEFT:
            setAnimation(MOVE_LEFT);
            break;
        default:
            break;
        }
    }
    else {
        switch (directionFacing){
        case UP_LEFT:
            setAnimation(IDLE_UP_LEFT);
            break;
        case UP:
            setAnimation(IDLE_UP);
            break;
        case UP_RIGHT:
            setAnimation(IDLE_UP_RIGHT);
            break;
        case RIGHT:
            setAnimation(IDLE_RIGHT);
            break;
        case DOWN_RIGHT:
            setAnimation(IDLE_DOWN_RIGHT);
            break;
        case DOWN:
            setAnimation(IDLE_DOWN);
            break;
        case DOWN_LEFT:
            setAnimation(IDLE_DOWN_LEFT);
            break;
        case LEFT:
            setAnimation(IDLE_LEFT);
            break;
        default:
            break;
        }
    }
}

bool Unit::isMoving() {
    return leftToMove != 0 || movingDown || movingUp || movingRight || movingLeft;
}

void Unit::draw()
{
    AnimatedSprite::draw();
    if (animations[ATTACK_UP_LEFT].active)
    {
        int k[2];
        scene->coordsFromTileIndex(tileLocation[0] - 1, tileLocation[1] - 1, k);
        scene->engine->renderAnimation(&animations[ATTACK_UP_LEFT], k[0], k[1], width, height);
    }
    if (animations[ATTACK_UP].active)
    {
        int k[2];
        scene->coordsFromTileIndex(tileLocation[0], tileLocation[1] - 1, k);
        scene->engine->renderAnimation(&animations[ATTACK_UP], k[0], k[1], width, height);
    }
    if (animations[ATTACK_UP_RIGHT].active)
    {
        int k[2];
        scene->coordsFromTileIndex(tileLocation[0] + 1, tileLocation[1] - 1, k);
        scene->engine->renderAnimation(&animations[ATTACK_UP_RIGHT], k[0], k[1], width, height);
    }
    if (animations[ATTACK_RIGHT].active)
    {
        int k[2];
        scene->coordsFromTileIndex(tileLocation[0] + 1, tileLocation[1], k);
        scene->engine->renderAnimation(&animations[ATTACK_RIGHT], k[0], k[1], width, height);
    }
    if (animations[ATTACK_DOWN_RIGHT].active)
    {
        int k[2];
        scene->coordsFromTileIndex(tileLocation[0] + 1, tileLocation[1] + 1, k);
        scene->engine->renderAnimation(&animations[ATTACK_DOWN_RIGHT], k[0], k[1], width, height);
    }
    //if (animations[ATTACK_DOWN].active)
    //{
    //    int k[2];
    //    scene->coordsFromTileIndex(tileLocation[0], tileLocation[1] + 1, k);
    //    scene->engine->renderAnimation(&animations[ATTACK_DOWN], k[0], k[1], width, height);
    // }
    if (animations[ATTACK_DOWN_LEFT].active)
    {
        int k[2];
        scene->coordsFromTileIndex(tileLocation[0] - 1, tileLocation[1] + 1, k);
        scene->engine->renderAnimation(&animations[ATTACK_DOWN_LEFT], k[0], k[1], width, height);
    }
    if (animations[ATTACK_LEFT].active)
    {
        int k[2];
        scene->coordsFromTileIndex(tileLocation[0] - 1, tileLocation[1], k);
        scene->engine->renderAnimation(&animations[ATTACK_LEFT], k[0], k[1], width, height);
    }
}

void Unit::attack() {
    switch (directionFacing)
    {
    case UP_LEFT:
        animations[ATTACK_UP_LEFT].resetAnimation();
        break;
    case UP:
        animations[ATTACK_UP].resetAnimation();
        break;
    case UP_RIGHT:
        animations[ATTACK_UP_RIGHT].resetAnimation();
        break;
    case RIGHT:
        animations[ATTACK_RIGHT].resetAnimation();
        break;
    case DOWN_RIGHT:
        animations[ATTACK_DOWN_RIGHT].resetAnimation();
        break;
    case DOWN:
        //animations[ATTACK_DOWN].resetAnimation();
        playAnimation(ATTACK_DOWN);
        break;
    case DOWN_LEFT:
        animations[ATTACK_DOWN_LEFT].resetAnimation();
        break;
    case LEFT:
        animations[ATTACK_LEFT].resetAnimation();
        break;
    default:
        break;
    }
    
}
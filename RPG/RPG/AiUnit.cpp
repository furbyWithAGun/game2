#include "AiUnit.h"

//constants
const double RANDOM_MOVE_CHANCE = 0.005;

//constructors
AiUnit::AiUnit() : Unit() {
    init();
}

AiUnit::AiUnit(TileGridScene* gameScene) : Unit(gameScene) {
    init();
}

AiUnit::AiUnit(TileGridScene* gameScene, int startX, int startY) : Unit(gameScene, startX, startY) {
    init();
}

void AiUnit::init() {
    isStatic = false;
    isHostile = false;
    chanceToMoveEachTick = RANDOM_MOVE_CHANCE;
}

void AiUnit::update() {
    randomMovement();
    Unit::update();
}

void AiUnit::randomMovement() {
    if (leftToMove == 0 && scene->engine->randomDouble() <= chanceToMoveEachTick)
    {
        startMovement(scene->engine->randomInt(UP, RIGHT));
        setUnitState(UNIT_MOVING);
    }
}
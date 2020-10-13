#include "AiUnit.h"

//constructors
AiUnit::AiUnit() : Unit() {
    isStatic = false;
    isHostile = false;
    chanceToMoveEachTick = .01;
}

AiUnit::AiUnit(TileGridScene* gameScene) : Unit(gameScene) {
    scene = gameScene;
    isStatic = false;
    isHostile = false;
    chanceToMoveEachTick = .01;
}

void AiUnit::update() {
    updateMovement();
    randomMovement();
    Unit::update();
}

void AiUnit::randomMovement() {
    if (leftToMove == 0 && scene->engine->randomDouble() <= chanceToMoveEachTick)
    {
        startMovement(scene->engine->randomInt(NUM_DIRECTIONS - 1));
    }
}
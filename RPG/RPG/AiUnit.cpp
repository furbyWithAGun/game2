#include "AiUnit.h"

//constructors
AiUnit::AiUnit() : Unit() {
    isStatic = false;
    isHostile = false;
    chanceToMoveEachTick = .001;
}

AiUnit::AiUnit(Texture* spriteTexture, TileGridScene* gameScene) : Unit(spriteTexture, gameScene) {
    scene = gameScene;
    isStatic = false;
    isHostile = false;
    chanceToMoveEachTick = .1;
}

void AiUnit::update() {
    updateMovement();
    randomMovement();
}

void AiUnit::randomMovement() {
    if (leftToMove == 0 && scene->engine->randomDouble() <= chanceToMoveEachTick)
    {
        startMovement(scene->engine->randomInt(NUM_DIRECTIONS - 1));
    }
}
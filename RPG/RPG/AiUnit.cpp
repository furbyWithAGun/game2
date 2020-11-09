#include "AiUnit.h"
#include "RpgOverWorldScene.h"

//constants
const double RANDOM_MOVE_CHANCE = 0.005;

//constructors
AiUnit::AiUnit() : Unit() {
    init();
}

AiUnit::AiUnit(int unitType) : Unit(unitType) {
    init();
}

AiUnit::AiUnit(int unitType, TileGridScene* gameScene) : Unit(unitType, gameScene) {
    init();
}

AiUnit::AiUnit(int unitType, TileGridScene* gameScene, int startX, int startY) : Unit(unitType, gameScene, startX, startY) {
    init();
}

void AiUnit::init() {
    isStatic = false;
    isHostile = false;
    chanceToMoveEachTick = RANDOM_MOVE_CHANCE;
}

void AiUnit::update() {
    if (!attackNearbyUnit())
    {
        randomMovement();
    }
    Unit::update();
}


void AiUnit::randomMovement() {
    if (leftToMove == 0 && scene->engine->randomDouble() <= chanceToMoveEachTick)
    {
        startMovement(scene->engine->randomInt(UP, RIGHT));
        setUnitState(UNIT_MOVING);
    }
}

bool AiUnit::attackNearbyUnit() {
    for (size_t i = 0; i < NUM_DIRECTIONS; i++)
    {
        if (meleeAttackUnitInDirection(i)) {
            return true;
        }
    }
    return false;
}

bool AiUnit::meleeAttackUnitInDirection(int direction)
{
    Unit* targetUnit;
    int x, y, coords[2];
    switch (direction)
    {
    case UP_LEFT:
        x = tileLocation[0] - 1;
        y = tileLocation[1] - 1;
        break;
    case UP:
        x = tileLocation[0];
        y = tileLocation[1] - 1;
        break;
    case UP_RIGHT:
        x = tileLocation[0] + 1;
        y = tileLocation[1] - 1;
        break;
    case RIGHT:
        x = tileLocation[0] + 1;
        y = tileLocation[1];
        break;
    case DOWN_RIGHT:
        x = tileLocation[0] + 1;
        y = tileLocation[1] + 1;
        break;
    case DOWN:
        x = tileLocation[0];
        y = tileLocation[1] + 1;
        break;
    case DOWN_LEFT:
        x = tileLocation[0] - 1;
        y = tileLocation[1] + 1;
        break;
    case LEFT:
        x = tileLocation[0] - 1;
        y = tileLocation[1];
        break;
    default:
        break;
    }
    targetUnit = scene->getUnitAtLocation(x, y);
    if (targetUnit != NULL && targetUnit->type == PLAYER)
    {
        scene->coordsFromTileIndex(x, y, coords);
        handleInput(&InputMessage(PERFORM_MAIN_ATTACK, coords[0], coords[1]));
        return true;
    }
    return false;
}

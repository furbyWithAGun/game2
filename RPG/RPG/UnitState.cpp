#include "UnitState.h"
#include "Unit.h"

//constructors
UnitState::UnitState() {
    init();
}

UnitState::UnitState(int newId, Unit* controlledUnit) {
    init();
    id = id;
    unit = controlledUnit;
}

//private methods
void UnitState::init() {
    id = -1;
    unit = NULL;
}
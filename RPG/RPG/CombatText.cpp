#include "CombatText.h"

const int DEFAULT_COMBAT_TEXT_DURATION = 30;
const int DEFAULT_COMBAT_TEXT_X_SPEED = 1;
const int DEFAULT_COMBAT_TEXT_Y_SPEED = 1;

CombatText::CombatText() {
    init();
}

CombatText::CombatText(std::string newText, int newTileX, int newTileY) {
    init();
    text = newText;
    tileX = newTileX;
    tileY = newTileY;
    duration = DEFAULT_COMBAT_TEXT_DURATION;
}

CombatText::CombatText(std::string newText, int newTileX, int newTileY, int newDuration) {
    init();
    text = newText;
    tileX = newTileX;
    tileY = newTileY;
    duration = newDuration;
}

//private Methods
void CombatText::init() {
    text = "";
    tileX = tileY = duration = tickCount = 0;
    xSpeed = DEFAULT_COMBAT_TEXT_X_SPEED;
    ySpeed = DEFAULT_COMBAT_TEXT_Y_SPEED;
}
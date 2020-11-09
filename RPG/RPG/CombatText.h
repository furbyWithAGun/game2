#pragma once
#include <string>

class CombatText
{
public:
    //attributes
    std::string text;
    int tileX, tileY, duration, tickCount, xSpeed, ySpeed;

    //constructors
    CombatText();
    CombatText(std::string newText, int newTileX, int newTileY);
    CombatText(std::string newText, int newTileX, int newTileY, int newDuration);

private:
    //methods
    void init();
};


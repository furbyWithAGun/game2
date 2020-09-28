#pragma once
#include <string>
#include <vector>

class ZonePortal
{
    public:
        //attributes
        int id;
        std::vector <int> tileCoords;
        int exitZoneId;
        std::vector <int> exitTileCoords;

        //constructors
        ZonePortal();
        ZonePortal(int newId, std::vector <int> newTileCoords, int newExitZoneId, std::vector <int> newExitTileCoords);
        ZonePortal(std::string saveString);

        //methods
        std::string toSaveString();
};


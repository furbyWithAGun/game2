#pragma once
#include <vector>
#include "MapTile.h"
#include "ZonePortal.h"
#include <string>

enum ZONE_MAP_ATTRIBUTES{
    ZONE_MAP_ID,
    TILE_MAP,
    PORTALS
};

class ZoneMap {
    public:
        //attributes
        int id;
        std::vector< std::vector<int> > tileMap;
        std::vector<ZonePortal> portals;

        //constructors
        ZoneMap(int newId, std::vector< std::vector<int> > tiles);
        ZoneMap(int newId);
        ZoneMap(SaveObject saveObject);
        ZoneMap();

        //methods
        void assignNewTileMap(std::vector< std::vector<int> > tiles);
        std::string toSaveString();

    private:
        //methods
        std::string getPortalVectorSaveString(std::vector<ZonePortal> vector);
        std::vector<ZonePortal> getPortalVectorFromSaveString(std::string saveString);
};


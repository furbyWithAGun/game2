#pragma once
#include <vector>
#include "MapTile.h"
#include "ZonePortal.h"
#include <string>

class ZoneMap{
    public:
        //attributes
        int id;
        std::vector< std::vector<int> > tileMap;
        std::vector<ZonePortal> portals;

        //constructors
        ZoneMap(std::vector< std::vector<int> > tiles);
        ZoneMap();

        //methods
        void assignNewTileMap(std::vector< std::vector<int> > tiles);
        std::string toSaveString();
};


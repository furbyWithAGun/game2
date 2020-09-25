#pragma once
#include <vector>
#include "MapTile.h"

class ZoneMap
{
    public:
        //attributes
        std::vector< std::vector<int> > tileMap;

        //constructors
        ZoneMap(std::vector< std::vector<int> > tiles);
        ZoneMap();

        //methods
        void assignNewTileMap(std::vector< std::vector<int> > tiles);
};


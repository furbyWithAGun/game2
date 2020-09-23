#pragma once
#include <vector>
#include "MapTile.h"

class ZoneMap
{
    public:
        std::vector< std::vector<int> > tileMap;
        ZoneMap(std::vector< std::vector<int> > tiles);
        ZoneMap();
        void assignNewTileMap(std::vector< std::vector<int> > tiles);
};


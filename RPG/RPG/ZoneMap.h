#pragma once
#include <vector>

class ZoneMap
{
    public:
        std::vector< std::vector<int> > tileMap;
        ZoneMap(std::vector< std::vector<int> > tiles);
};


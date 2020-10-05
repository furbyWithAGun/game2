#pragma once
class MapTile
{
    public:
        //attributes
        bool passable;
        int textureKey;

        //constructor
        MapTile(bool tileIsPassable, int tileTextureKey);
        MapTile();

        // deconstructor
        ~MapTile();

        //methods
};
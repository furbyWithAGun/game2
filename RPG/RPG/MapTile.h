#pragma once
class MapTile
{
    public:
        int id;
        bool passable;
        int textureKey;
        MapTile(int tileId, bool tileIsPassable, int tileTextureKey);
};
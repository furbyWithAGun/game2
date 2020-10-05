#include "MapTile.h"

MapTile::MapTile(bool tileIsPassable, int tileTextureKey) {
    passable = tileIsPassable;
    textureKey = tileTextureKey;
}

MapTile::MapTile() {
    passable = false;
    textureKey = 0;
}

MapTile::~MapTile() {
    passable = false;
    textureKey = 0;
}

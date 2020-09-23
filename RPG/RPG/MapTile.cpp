#include "MapTile.h"

MapTile::MapTile(int tileId, bool tileIsPassable, int tileTextureKey) {
    id = tileId;
    passable = tileIsPassable;
    textureKey = tileTextureKey;
}

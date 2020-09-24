#include "MapTile.h"

MapTile::MapTile(bool tileIsPassable, int tileTextureKey) {
    passable = tileIsPassable;
    textureKey = tileTextureKey;
}

MapTile::MapTile() {

}

#include "ZoneMap.h"
#include "RpgGameEngine.h"

ZoneMap::ZoneMap(int newId, std::vector< std::vector<int> > tiles) {
	id = newId;
	assignNewTileMap(tiles);
}

ZoneMap::ZoneMap(int newId) {
	id = newId;
}

ZoneMap::ZoneMap() {
	id = -1;
}


void ZoneMap::assignNewTileMap(std::vector< std::vector<int> > tiles) {
	if (tiles.size() > 0)
	{
		tileMap.resize(tiles.size());
		for (int i = 0; i < tiles.size(); i++)
		{
			if (tiles[i].size() > 0)
			{
				tileMap[i].resize(tiles[i].size());
				for (int j = 0; j < tiles[i].size(); j++) {
					tileMap[i][j] = tiles[i][j];
				}
			}
		}
	}
}

std::string ZoneMap::toSaveString() {
	std::string saveString;

	saveString = BEGIN_OBJECT_IDENTIFIER + std::to_string(ZONE_MAP) + "\n";
	saveString += getAttributeString(ID, id);
	saveString += getAttributeString(TILE_MAP, get2DIntVectorSaveString(tileMap));
	saveString += getAttributeString(PORTALS, getPortalVectorSaveString(portals));
	saveString += END_OBJECT_IDENTIFIER + std::to_string(ZONE_MAP) + "\n";

	return saveString;
}

std::string ZoneMap::getPortalVectorSaveString(std::vector<ZonePortal> vector) {
	std::string returnString;
	returnString += std::to_string(vector.size()) + "\n";
	for (int i = 0; i < vector.size(); i++)
	{
		returnString += vector[i].toSaveString() + "\n";
	}

	printf("1d vector: %s", returnString.c_str());
	return returnString;
}
#include "ZoneMap.h"
#include "RpgGameEngine.h"
#include "SaveFile.h"

ZoneMap::ZoneMap(int newId, std::vector< std::vector<int> > tiles) {
	id = newId;
	assignNewTileMap(tiles);
}

ZoneMap::ZoneMap(int newId) {
	id = newId;
}

ZoneMap::ZoneMap(SaveObject saveObject) {
	for (int i = 0; i < saveObject.attributes.size(); i++)
	{
		switch (saveObject.attributes[i].attributeType) {
		case ZONE_MAP_ID:
			id = stoi(saveObject.attributes[i].valueString);
			break;
		case TILE_MAP:
			tileMap = get2dIntVectorFromSaveString(saveObject.attributes[i].valueString);
			break;
		case PORTALS:
			portals = getPortalVectorFromSaveString(saveObject.attributes[i].valueString);
			break;
		default:
			break;
		}
	}
}

ZoneMap::ZoneMap() {
	id = -1;
}

ZoneMap::~ZoneMap() {
	id = 0;
	tileMap.clear();
	portals.clear();
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
	int uniqueObjectId = getUniqueId();

	saveString = BEGIN_OBJECT_IDENTIFIER + std::to_string(uniqueObjectId) + "-" + std::to_string(ZONE_MAP) + "\n";
	saveString += getAttributeString(getUniqueId(), ZONE_MAP_ID, id);
	saveString += getAttributeString(getUniqueId(), TILE_MAP, get2DIntVectorSaveString(tileMap));
	saveString += getAttributeString(getUniqueId(), PORTALS, getPortalVectorSaveString(portals));
	saveString += END_OBJECT_IDENTIFIER + std::to_string(uniqueObjectId) + "-" + std::to_string(ZONE_MAP) + "\n";

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

std::vector<ZonePortal> ZoneMap::getPortalVectorFromSaveString(std::string saveString) {
	std::vector<ZonePortal> returnVector;

	std::vector<SaveObject> savedPortals = getSaveObjectVectorFromSaveString2(saveString);

	for (size_t i = 0; i < savedPortals.size(); i++)
	{
		returnVector.push_back(ZonePortal(savedPortals[i].rawString));
	}


	return returnVector;
}
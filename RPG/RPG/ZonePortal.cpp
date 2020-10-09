#include "ZonePortal.h"
#include <string>
#include "BaseGameEngine.h"
#include "SaveFile.h"
#include "RpgGameConstants.h"

ZonePortal::ZonePortal() {
    id = -1;
    exitZoneId = -1;
}

ZonePortal::ZonePortal(int newId, std::vector <int> newTileCoords, int newExitZoneId, std::vector <int> newExitTileCoords) {
    id = newId;
    tileCoords = newTileCoords;
    exitZoneId = newExitZoneId;
    exitTileCoords = newExitTileCoords;
}

ZonePortal::ZonePortal(SaveObject saveObject) {
    for (int i = 0; i < saveObject.attributes.size(); i++)
    {
        switch (saveObject.attributes[i].attributeType) {
        case ZONE_PORTAL_ID:
            id = stoi(saveObject.attributes[i].valueString);
            break;
        case TILE_COORDS:
            tileCoords = getIntVectorFromSaveString(saveObject.attributes[i].valueString);
            break;
        case EXIT_ZONE_ID:
            exitZoneId = stoi(saveObject.attributes[i].valueString);
            break;
        case EXIT_TILE_COORDS:
            exitTileCoords = getIntVectorFromSaveString(saveObject.attributes[i].valueString);
            break;
        default:
            break;
        }
    }
}

ZonePortal::~ZonePortal() {
    id = 0;
    tileCoords.clear();
    exitZoneId = 0;
    exitTileCoords.clear();
}

std::string ZonePortal::toSaveString() {
    std::string saveString;
    int uniqueObjectId = getUniqueId();

    saveString = BEGIN_OBJECT_IDENTIFIER + std::to_string(uniqueObjectId) + "-" + std::to_string(ZONE_PORTAL) + "\n";
    saveString += getAttributeString(getUniqueId(), ZONE_PORTAL_ID, id);
    saveString += getAttributeString(getUniqueId(), TILE_COORDS, getIntVectorSaveString(tileCoords));
    saveString += getAttributeString(getUniqueId(), EXIT_ZONE_ID, exitZoneId);
    saveString += getAttributeString(getUniqueId(), EXIT_TILE_COORDS, getIntVectorSaveString(exitTileCoords));
    saveString += END_OBJECT_IDENTIFIER + std::to_string(uniqueObjectId) + "-" + std::to_string(ZONE_PORTAL) + "\n";

    return saveString;
}
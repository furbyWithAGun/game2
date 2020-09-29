#include "ZonePortal.h"
#include <string>
#include "BaseGameEngine.h"
#include "RpgGameEngine.h"
#include "SaveFile.h"

ZonePortal::ZonePortal() {

}

ZonePortal::ZonePortal(int newId, std::vector <int> newTileCoords, int newExitZoneId, std::vector <int> newExitTileCoords) {
    id = newId;
    tileCoords = newTileCoords;
    exitZoneId = newExitZoneId;
    exitTileCoords = newExitTileCoords;
}

ZonePortal::ZonePortal(SaveObject saveObject) {

}

std::string ZonePortal::toSaveString() {
    std::string saveString;

    saveString = BEGIN_OBJECT_IDENTIFIER + std::to_string(ZONE_PORTAL) + "\n";
    saveString += getAttributeString(ID, id);
    saveString += getAttributeString(TILE_COORDS, getIntVectorSaveString(tileCoords));
    saveString += getAttributeString(EXIT_ZONE_ID, exitZoneId);
    saveString += getAttributeString(EXIT_TILE_COORDS, getIntVectorSaveString(exitTileCoords));
    saveString += END_OBJECT_IDENTIFIER + std::to_string(ZONE_PORTAL) + "\n";

    return saveString;
}
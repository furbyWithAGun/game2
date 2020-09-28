#include "ZonePortal.h"
#include <string>
#include "BaseGameEngine.h"

ZonePortal::ZonePortal() {

}

ZonePortal::ZonePortal(int newId, std::vector <int> newTileCoords, int newExitZoneId, std::vector <int> newExitTileCoords) {
    id = newId;
    tileCoords = newTileCoords;
    exitZoneId = newExitZoneId;
    exitTileCoords = newExitTileCoords;
}

ZonePortal::ZonePortal(std::string saveString) {

}

std::string ZonePortal::toSaveString() {
    std::string saveString;
    saveString = "BEGIN OBJECT ZONEPORTAL\n";
    saveString += "BEGIN ID\n" + std::to_string(id) + "\n";
}
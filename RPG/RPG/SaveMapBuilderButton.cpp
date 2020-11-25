#include "SaveMapBuilderButton.h"

//constructors
SaveMapBuilderButton::SaveMapBuilderButton() : MenuButton() {
    scene = NULL;
}

SaveMapBuilderButton::SaveMapBuilderButton(int buttonTextureKey, RpgWorldBuilderScene* gameScene) : MenuButton(buttonTextureKey, gameScene) {
    scene = gameScene;
}

void SaveMapBuilderButton::onClick() {
    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    firstZoneFile.addSaveObjectString(scene->currentZone.toSaveString());
    firstZoneFile.saveFile();
}
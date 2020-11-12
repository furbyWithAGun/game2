#include "SaveMapBuilderButton.h"

//constructors
SaveMapBuilderButton::SaveMapBuilderButton() : MenuButton() {
    engine = NULL;
    scene = NULL;
}

SaveMapBuilderButton::SaveMapBuilderButton(int buttonTextureKey, RpgWorldBuilderScene* gameScene) : MenuButton(buttonTextureKey, gameScene) {
    scene = gameScene;
    engine = gameScene->engine;
}

void SaveMapBuilderButton::onClick() {
    SaveFile firstZoneFile = SaveFile("zoneOne.txt");
    firstZoneFile.addSaveObjectString(scene->currentZone.toSaveString());
    firstZoneFile.saveFile();
}
// Includes
#include "RpgGameEngine.h"
#include "ZoneMap.h"
#include "SaveFile.h"

// Global Constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;

int main(int argc, char* args[])
{
    //local vars
    RpgGameEngine engine = RpgGameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    std::string string = "BEGIN OBJECT 1\nBEGIN ATTRIBUTE 1\nBEGIN OBJECT 3\nBEGIN ATTRIBUTE 8\n10\nEND ATTRIBUTE 8\nEND OBJECT 3\nEND ATTRIBUTE 1\nBEGIN ATTRIBUTE 2\n3\nEND ATTRIBUTE 2\nBEGIN ATTRIBUTE 3\n4\nEND ATTRIBUTE 3\nEND OBJECT 1\nBEGIN OBJECT 1\nBEGIN ATTRIBUTE 2\n3\nEND ATTRIBUTE 2\nBEGIN ATTRIBUTE 3\n4\nEND ATTRIBUTE 3\nEND OBJECT 1";
    SaveObject object = SaveObject(string);
    printf("Object class: %i\n",object.objectClass);
    for (int i = 0; i < object.attributes.size(); i++)
    {
        printf("attribute type: %i, attribute value: %s \n",object.attributes[i].attributeType, object.attributes[i].valueString.c_str());
    }
    
    SaveFile file = SaveFile("./testfile.txt");
    //file.addSaveObjectString(string);
    //file.populateAllObjects();
    //file.saveFile();
    file.loadFile();

    engine.init();
    engine.setUpGame();
    engine.startMainGameLoop();

    //terminate the engine
    engine.close();
    //std::getchar();
    return 0;
}
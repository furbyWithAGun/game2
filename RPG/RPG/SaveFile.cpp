#include "SaveFile.h"
#include "SaveObject.h"
#include <fstream>

//static methods
void SaveFile::saveStringToFile(std::string string, std::string filePath) {
    std::ofstream file(filePath.c_str());
    if (file.is_open()) {
        file << string;
        file.close();
    }
    else {
        printf("could not save file %s", filePath.c_str());
    }
}

std::string SaveFile::loadStringFromFile(std::string filePath) {
    std::string returnString;
    std::string line;
    std::ifstream file(filePath.c_str());
    if (file.is_open()) {
        while (std::getline(file, line)) {
            returnString += line + "\n";
        }
        file.close();
    }
    return returnString;
}

//contstructos
SaveFile::SaveFile() {
    rawString = "";
    filePath = "";
    retrievedObjects = 0;
    index = 0;
}

SaveFile::SaveFile(std::string newFilePath) {
    filePath = newFilePath;
    rawString = "";
    retrievedObjects = 0;
    index = 0;
}


//public methods
void SaveFile::reset() {
    retrievedObjects = 0;
    index = 0;
}

void SaveFile::saveFile() {
    SaveFile::saveStringToFile(rawString, filePath);
}

void SaveFile::loadFile() {
    rawString = SaveFile::loadStringFromFile(filePath);
    populateAllObjects();
}

void SaveFile::addSaveObjectString(std::string saveString) {
    rawString += saveString;
}

//private methods
std::string SaveFile::getNextSaveObjectString() {
    std::string subString = rawString.substr(index);
    std::string nextObjectId = getSubstrBeginEndWithExclusive(subString, BEGIN_OBJECT_IDENTIFIER, "\n");
    return getSubstrBeginEndWithInclusive(rawString, BEGIN_OBJECT_IDENTIFIER + nextObjectId, END_OBJECT_IDENTIFIER + nextObjectId, 0, &index);
}

SaveObject SaveFile::getNextSaveObject() {
    std::string objectString = getNextSaveObjectString();
    SaveObject returnObject;

    if (objectString.compare("") != 0)
    {
        returnObject = SaveObject(objectString);
        retrievedObjects += 1;
    }
    else {
        reset();
    }

    return returnObject;
}

void SaveFile::populateAllObjects() {
    SaveObject saveObject;
    bool continueLoop = true;
    while (continueLoop)
    {
        saveObject = getNextSaveObject();
        if (saveObject.rawString.compare("") != 0)
        {
            objects.push_back(saveObject);
        }
        else {
            continueLoop = false;
        }
    }
}
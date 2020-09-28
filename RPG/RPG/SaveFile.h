#pragma once
#include <string>
#include "SaveObject.h"
#include <vector>

class SaveFile
{
    public:
        //static methods
        void saveStringToFile(std::string string, std::string filePath);
        std::string loadStringFromFile(std::string filePath);

        //attributes
        std::string filePath;
        std::string rawString;
        std::vector<SaveObject> objects;

        //constructors
        SaveFile();
        SaveFile(std::string newFilePath);

        //methods
        void reset();
        void saveFile();
        void loadFile();
        void addSaveObjectString(std::string saveString);


    private:
        //attributes
        int retrievedObjects;

        //methods
        SaveObject getNextSaveObject();
        void populateAllObjects();
        std::string getNextSaveObjectString();
        
};


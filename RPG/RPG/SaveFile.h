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
        std::string::size_type index;

        //constructors
        SaveFile();
        SaveFile(std::string newFilePath);

        //methods
        void reset();
        void saveFile();
        void loadFile();
        void addSaveObjectString(std::string saveString);

        void populateAllObjects();

    private:
        //attributes
        int retrievedObjects;

        //methods
        SaveObject getNextSaveObject();
        
        std::string getNextSaveObjectString();
        
};


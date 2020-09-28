#pragma once
#include <string>
#include "SaveAttribute.h"
#include <vector>

const std::string BEGIN_OBJECT_IDENTIFIER = "BEGIN OBJECT ";
const std::string END_OBJECT_IDENTIFIER = "END OBJECT\n";

class SaveObject
{
    public:
        //attributes
        int objectClass;
        std::string rawString;
        std::vector<SaveAttribute> attributes;

        //constructors
        SaveObject();
        SaveObject(std::string saveString);

        //methods
        void reset();
        

    private:
        //attributes
        int retrievedAttributes;

        //methods
        std::string getNextSaveAttributeString();
        void populateAllAttributes();
        SaveAttribute getNextSaveAttribute();
};


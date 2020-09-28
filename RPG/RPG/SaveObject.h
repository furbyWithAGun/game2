#pragma once
#include <string>

class SaveObject
{
    public:
        std::string rawString;
        std::string::size_type index1, index2;
        int objectClass;

        //constructors
        SaveObject();
        SaveObject(std::string saveString);

        //methods
        void reset();
        std::string getNextAttributeString();
};


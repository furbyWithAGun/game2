#include "SaveObject.h"

const std::string BEGIN_ATTRIBUTE_IDENTIFIER = "BEGIN ATTRIBUTE";
const std::string END_ATTRIBUTE_IDENTIFIER = "END ATTRIBUTE";


SaveObject::SaveObject() {
    rawString = "";
    index1 = 0;
    index2 = 0;
}

SaveObject::SaveObject(std::string saveString) {
    rawString = saveString;
    index1 = 0;
    index2 = 0;
}

void SaveObject::reset() {
    index1 = 0;
    index2 = 0;
}

std::string SaveObject::getNextAttributeString() {
    std::string returnString = "";
    for (std::string::size_type i = index1; i < rawString.size(); i++) {
        if (rawString.substr(i, BEGIN_ATTRIBUTE_IDENTIFIER.size()).compare(BEGIN_ATTRIBUTE_IDENTIFIER) == 0)
        {
            index1 = i;
        } else if (rawString.substr(i, END_ATTRIBUTE_IDENTIFIER.size()).compare(END_ATTRIBUTE_IDENTIFIER) == 0){
            index2 = i + END_ATTRIBUTE_IDENTIFIER.size();
            break;
        }
    }
    returnString = rawString.substr(index1, index2 - index1);
    index1 = index2;
    return returnString;
}
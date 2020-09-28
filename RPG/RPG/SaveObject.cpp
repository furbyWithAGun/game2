#include "SaveObject.h"

SaveObject::SaveObject() {
    rawString = "";
    objectClass = -1;
    retrievedAttributes = 0;
}

SaveObject::SaveObject(std::string saveString) {
    rawString = saveString;
    objectClass = std::stoi(getSubstrBeginEndWithExclusive(rawString, BEGIN_OBJECT_IDENTIFIER, "\n"));
    retrievedAttributes = 0;
    populateAllAttributes();
}

void SaveObject::reset() {
    retrievedAttributes = 0;
}

SaveAttribute SaveObject::getNextSaveAttribute() {
    std::string attributeString = getNextSaveAttributeString();
    SaveAttribute returnAttribute;

    if (attributeString.compare("") != 0)
    {
        returnAttribute = SaveAttribute(attributeString);
        retrievedAttributes += 1;
    }
    else {
        reset();
    }

    return returnAttribute;
}

std::string SaveObject::getNextSaveAttributeString() {
    return getSubstrBeginEndWithInclusive(rawString, BEGIN_ATTRIBUTE_IDENTIFIER , END_ATTRIBUTE_IDENTIFIER, retrievedAttributes);
}

void SaveObject::populateAllAttributes() {
    SaveAttribute saveAttribute;
    bool continueLoop = true;
    while (continueLoop)
    {
        saveAttribute = getNextSaveAttribute();
        if (saveAttribute.valueString.compare("") != 0)
        {
            attributes.push_back(saveAttribute);
        }
        else {
            continueLoop = false;
        }
    }
}
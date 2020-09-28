#include "SaveFile.h"
#include "SaveObject.h"

SaveFile::SaveFile() {
    rawString = "";
    index1 = 0;
    index2 = 0;
}

SaveFile::SaveFile(std::string saveString) {
    rawString = saveString;
    index1 = 0;
    index2 = 0;
}

#include <iostream>
#include "OpenFile.h"
#include "FileStatusToOpen.h"


void fillVector(std::vector<std::string>& vec, const std::string& str) {
    OpenFile fileClass(str, READ);
    fileClass.fileToVector(vec);
}

void fillAccountVector(std::vector<Account>& vec, const std::string& str) {
    OpenFile fileClass(str, READ);
    fileClass.fileToAccountVector(vec);
}

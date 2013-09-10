
#include <string>
#include <vector>

#include "FileStatusToOpen.h"
#include "OpenFile.h"
#include "account.h"




void writeVectorToFile(const std::vector<std::string>& vec, const std::string& filename){
    OpenFile fileClass(filename, OVERWRITE);
    fileClass.overwriteToFile(vec);
}

void writeVectorToFile(const std::vector<Account>& vec, const std::string& filename){
    OpenFile fileClassB(filename, OVERWRITE);
    fileClassB.overwriteToFile(vec);
}

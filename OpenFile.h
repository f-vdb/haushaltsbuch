
#ifndef OPEN_FILE_H
#define OPEN_FILE_H  

#include <fstream>
#include <string>
#include <vector>
#include "FileStatusToOpen.h"
#include "account.h"

class OpenFile {
public:
  OpenFile(const std::string str, const FileStatusToOpen fileStatus);
  ~OpenFile();
  void fileToVector(std::vector<std::string>& vec);
  void fileToAccountVector(std::vector<Account>& vec);
  void overwriteToFile(const std::vector<std::string>& vec);
  void overwriteToFile(const std::vector<Account>& vec);
private:
  OpenFile(const OpenFile& );  // no implicit use of the copyconsturctor
  std::fstream streamFile_;  
};

#endif // OPEN_FILE_H


#include <fstream>
#include <iostream>
#include <string>

#include "constants.h"
#include "timeStamp.h"

void error(const std::string& s, const std::string& s2 =""){
    std::cerr << s << s2 << '\n';
    std::exit(1);
}

void makeBackup(){
    std::ifstream von(accountFile.c_str());
    if(!von)
        error("Kann folgende Datei Datei zum Lesen nicht oeffnen: ", accountFile);


    const std::string backupFileName = "BACKUP_" + getTimeStamp()+ ".txt";

    std::ofstream nach(backupFileName.c_str());
    if(!nach)
        error("Kann folgende Datei nicht zum Schreiben oeffnen: ",backupFileName);
    char ch;
    while(von.get(ch))
        nach.put(ch);
    if(!von.eof() || !nach)
        error("hier stimmt was nicht mit dem Backup\nFragen Sie...");
}



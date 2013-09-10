#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "OpenFile.h"
#include "DebugMsg.h"
#include "FileStatusToOpen.h"
#include "account.h"

OpenFile::OpenFile(const std::string str, const FileStatusToOpen fileStatus) {
    if(fileStatus == READ) {
        streamFile_.open(str.c_str(), std::fstream::in);
        if(!streamFile_) {
            DEBUG_MSG("Kann Datei nicht lesen, da nicht vorhanden: ");
            DEBUG_MSG("Lege die Datei an: " << str);
            std::ofstream of;
            of.open(str.c_str());
            of.close();
            of.clear();
            DEBUG_MSG("file " << str << " angelegt");
        }
        streamFile_.close();
        streamFile_.clear();
        streamFile_.open(str.c_str(), std::fstream::in);
        DEBUG_MSG("Datei " << str << " geoeffnet.");
    }
    if(fileStatus == OVERWRITE) {
        streamFile_.open(str.c_str(), std::fstream::out);
        if(!streamFile_) {
            DEBUG_MSG("Kann Datei nicht nutzen.... CODE 1234: ");
        }
    }
}

OpenFile::~OpenFile() {
    DEBUG_MSG("desructor fileHandler");
    streamFile_.close();
    streamFile_.clear();
}

void OpenFile::fileToVector(std::vector<std::string>& vec) {
    std::string str;
    while(std::getline(streamFile_, str))
        vec.push_back(str);
    std::sort(vec.begin(), vec.end());
}

void OpenFile::overwriteToFile(const std::vector<std::string>& vec) {
   for(const auto i : vec) {
       //std::cout << i << std::endl;
       streamFile_ << i << std::endl;
   }
}

void OpenFile::overwriteToFile(const std::vector<Account>& vec){
    std::string delimeter = "|";
    for(const auto i : vec) {
        streamFile_ << i.getOberkat() << delimeter 
                    << i.getKat() << delimeter 
                    << i.getTitle() << delimeter
                    << i.getDay() << delimeter
                    << i.getMonth() << delimeter
                    << i.getYear() << delimeter
                    << i.getAmount() << delimeter
                    << i.getTimestamp() 
                    << std::endl;
    }
}


void OpenFile::fileToAccountVector(std::vector<Account>& vec) {
    std::string line;
    std::string oberkat, kat, title, day, month, year, amount, timestamp;
    while(std::getline(streamFile_, line)){
        std::stringstream iss(line);
        //std::getline(iss, number, '|');
        std::getline(iss, oberkat, '|');
        std::getline(iss, kat, '|');
        std::getline(iss, title, '|');
        std::getline(iss, day, '|');
        std::getline(iss, month, '|');
        std::getline(iss, year, '|');
        std::getline(iss, amount, '|');
        std::getline(iss, timestamp, '|');
        std::cout << "oberkat: " << oberkat << std::endl;
        std::cout << "kat: " << kat << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "day: " << day << std::endl;
        std::cout << "month: " << month << std::endl;
        std::cout << "year: " << year << std::endl;
        std::cout << "amount: " << amount << std::endl;
        std::cout << "timestamp: " << timestamp << std::endl;
        if(timestamp.empty())
            timestamp = "20110118";
        Account A(oberkat, kat, title,
                  day, month,
                  year, std::stod(amount), timestamp);
        vec.push_back(A);
    }
}


#include <vector>
#include <iostream>
#include <string>
#include <assert.h>

#include "clrScreen.h"
#include "printVector.h"
#include "wrongInput.h"
#include "showOberkatMenu.h"

void loeschenOberkat(const std::string kat, std::vector<std::string>& vec) {
    clrScreen();
    if(vec.empty()) {
        std::cout << "\n\n\n\tNichts zu loeschen" << std::endl;
        return;
    }
    printVector(vec);
    std::cout << std::endl;
    std::cout << "\tWelche ";
    std::cout << kat << " loeschen (zurueck mit 0):   ";
    std::string line;
    size_t i;

    getline(std::cin, line); 
    if((line.empty()) || (line.size() > 1) || (!isdigit(line[0]))) {
        wrongInput();
        clrScreen();
        return; //continue;
    }
    char c =(char)line[0];
    if(c=='0') {
        clrScreen();
        return;
    }
    i = atoi(&c);
    if(i>vec.size()) {
        wrongInput();
        clrScreen();
        return; //continue;
    }

    std::vector<std::string>::iterator deleted = vec.begin() + i - 1;
    std::cout << "\n\n\n\n\n\t" << *deleted << " geloescht" << std::endl;

    vec.erase(vec.begin()+(i-1));
    std::cout << std::endl;
    std::cout << "\n\n\n\t" << std::endl;
    printVector(vec);
    std::cout << "\n\n\tweiter mit beliebiger Taste ";
    std::string tmp;
    getline(std::cin, tmp);
    clrScreen();
}

void addOberkat(const std::string kat, std::vector<std::string>& vec, const size_t MAXSIZE) {
    clrScreen();
    printVector(vec);
    std::cout << std::endl;
    std::cout << "\t" << kat << " eingeben (zurueck mit 0):   ";
    std::string line;
    getline(std::cin, line); 
    if((line=="0")) {
        clrScreen();
        return; //continue;
    }
    if(line.size() > MAXSIZE) {
        std::cout << "\n\n\tEingabe String zu lang! Maximal " << MAXSIZE;
        std::cout << " Zeichen erlaubt.\n\n";
        std::cout << "\tweiter mit beliebiger Taste ";
        std::string tmp;
        getline(std::cin, tmp);
        clrScreen();
        return;
    }
    vec.push_back(line);
    clrScreen();
    std::cout << "\n\n\n" << std::endl;
    std::cout << "\t" << kat << " " <<  line << " hinzugefuegt\n";
    std::cout << "\n\n\n" << std::endl;
    printVector(vec);
    std::cout << "\n\n\n\tweiter mit beliebiger Taste ";
    std::string tmp;
    getline(std::cin, tmp);
    clrScreen();
}


void oberkatVerwalten(const std::string kat, std::vector<std::string>& vec, const size_t MAXSIZE) {

    clrScreen();
    if(vec.empty())
        std::cout << "\n\n\tBisher noch keine " << kat << " vorhanden\n\n";
    else {
        std::cout << "\n\n\tErfasste " << kat << ":\n";
        std::cout <<     "\t=========";
        for(size_t i = 0; i != kat.size()+1; ++i)
            std::cout << "=";
        std::cout << "\n\n";
    }
    printVector(vec);
    std::cout << "\n\n";
    std::cout << "\t" << kat << " verwalten" << std::endl;
    std::cout << "\t";
    for(size_t i = 0; i != kat.size()+1; ++i)
        std::cout << "=";
    std::cout << "=========";
    showOberkatMenu();
    std::string line;
    while( getline(std::cin, line) ) {
        if ( (line.empty()) || (line.size() > 1) || (!isdigit(line[0])) ){ 
            wrongInput();
            clrScreen();
            printVector(vec);
            showOberkatMenu();
            continue;
        }
        const char input = (char)line[0];  // is this a good cast (ok casts are never friends)
        switch(input) {
            case '1': clrScreen();
                      printVector(vec);
                      addOberkat(kat, vec, MAXSIZE);
                      printVector(vec);
                      oberkatVerwalten(kat, vec, MAXSIZE);
                      return;
            case '2': clrScreen();
                      printVector(vec);
                      loeschenOberkat(kat, vec);
                      printVector(vec);
                      oberkatVerwalten(kat, vec, MAXSIZE);
                      return;
            case '0': clrScreen();
                      return; 
            default:  assert("should never get here"); 
        }
    }
}


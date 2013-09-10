
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>


#include "account.h"
#include "writeVectorToFile.h"
#include "constants.h"
#include "userInputsNumber.h"



void showTimeframe(std::vector<Account>& vecAccount, bool print){
    std::vector<Account> vecTmp;
    unsigned int tmp;
    std::string year;
    std::string month;
    char c;

    // siehe account.cpp zeile 275
    std::cout << "Monat: ";
    tmp = userInputsNumber(12)+1;
    if(tmp < 10){
        month = std::to_string(tmp);
        month = "0" + month;
    }
    else
        month = std::to_string(tmp);

        
    while(1){
        std::cout << "Jahr: ";
        std::cin.get(c);
        if(c=='\n'){
            year = "";
            std::cout << "falsches Jahr versuche erneut...\n";
            continue;
        }
        std::cin.putback(c);
        getline(std::cin, year);
        break;
    }

    for(const auto i : vecAccount) {
        if(i.getMonth()==month && i.getYear()==year)
            vecTmp.push_back(i);
    }
    if(print == true){
        std::string filename = "ausgaben_" + year + "_" + month + ".txt";
        std::ofstream out(filename.c_str());
        std::streambuf* coutbuf = std::cout.rdbuf(); // save old buf
        std::cout.rdbuf(out.rdbuf()); // redirect std::cout to file out
        showForPrint(vecTmp, true);
        std::cout.rdbuf(coutbuf); // reset to standard output again
        out.close();
    }
    else
        showForPrint(vecTmp, true);
}

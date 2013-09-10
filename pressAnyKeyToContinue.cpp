
#include <iostream>
#include <string>

#include "clrScreen.h"

void pressAnyKeyToContinue(){
    std::cout << "\n\n\n\tweiter mit beliebiger Taste ";
    std::string tmp;
    getline(std::cin, tmp);
    clrScreen();
}

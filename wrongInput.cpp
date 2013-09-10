
#include<iostream>
#include<string>
#include"wrongInput.h"
void wrongInput() {
			std::cout << "\n\t" 
                << "falsche eingabe\n"
                << " weiter mit beliebiger taste";
			std::string tmp;
			getline(std::cin, tmp); 
}


#include <iostream>
#include <string>
#include <vector>

#include "account.h"


void deleteSomeAccount(std::vector<Account>& vecAccount, size_t i){
    vecAccount.erase(vecAccount.begin()+i-1);
    std::cout << "deleteSomeAccount" << std::endl;
}

void deleteLastAccount(std::vector<Account>& vecAccount) {
    vecAccount.pop_back();
    std::cout << "Letzte Eingabe geloescht!\n\n";
}


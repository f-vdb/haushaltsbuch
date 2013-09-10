
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

#include "buildMenu.h"
#include "timeStamp.h"

void buildMenu(const std::vector<std::string>& vec, const std::string& name, const size_t& columns,
        const bool& count, const bool& end) {
    assert(columns!=0);
    size_t sizeName = name.size();
    std::cout << "\n\n";
    if(name.size()!=0) {
        std::cout << "\t" << name << std::endl;
        std::cout << "\t";
        for(size_t i = 0; i != sizeName; ++i)
            std::cout << "=";
        std::cout << std::endl;
    }
    size_t c = 0;
    for(size_t i = 0; i != vec.size(); ++i) {
        if(c==columns) {
            std::cout << std::endl << std::endl;
            c = 0;
        }
        std::cout << "\t" << i + 1 << ": " << vec[i] << "\t";
        c++;
    }
    std::cout << std::endl << std::endl;
    if(end==true) {
        std::cout << "\t0: Ende\n\n";
    }
    if(count==true) {
        std::cout << "\tAnzahl der Posten: keine Ahnung" << "\n\n";
    }
    std::cout << std::endl << std::endl;
    std::cout << "\tDeine Wahl: ";
}

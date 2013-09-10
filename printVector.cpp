
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "printVector.h"
#include "constants.h"


void printVector(std::vector<std::string>& vec) {
    size_t count = 0;
    size_t number = 1;
    std::sort(vec.begin(), vec.end());
    for(const auto item : vec) {
        if (count == 3) {
            std::cout << "\n";
            count = 0;
        }
        std::cout << "\t";
        // fieldwidth 
        std::cout.width(2);
        std::cout << number << ") ";
        // fieldwidth 
        std::cout.width(KAT_STRING_SIZE+1);
        // left-adjusted
        std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
        std::cout << item << " ";
        // standard fieldwidth
        std::cout.width(0);
        // standard alignment
        std::cout.setf(std::ios_base::right, std::ios_base::adjustfield); 
        count++;
        number++;
    }
    std::cout << std::endl;
}



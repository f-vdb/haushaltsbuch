#include <string>
#include <iostream>

unsigned int userInputsNumber(unsigned int size) {
        char c = 0;
        unsigned int wahl;
        std::string input;
        std::cin.clear();
        while(1){
            std::cin.get(c);
            if(c=='\n'){
                std::cout << "Bitte Zahl eingeben!\n";
                continue;
            }
            std::cin.putback(c);
            //std::cin >> input;  <--- cin doesn't read the '\n'
            //                         and so the '\n' will be in the stream
            getline(std::cin, input);
            try{       
                wahl = stoi(input);
            }catch(...){
                std::cout << "Bitte Zahl eingeben!\n";
                continue;
            }
            //if(wahl < 1 || wahl > size){
            if(wahl > size){ // zero is okay too
                std::cout << "falsche Eingabe" << std::endl;
                continue;
            }
            break;
        }
        std::cin.clear();
        return wahl-1;
}

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

#include "clrScreen.h"
#include "wrongInput.h"
#include "showMainMenu.h"
#include "DebugMsg.h"
#include "fillVector.h"
#include "printVector.h"
#include "oberkatVerwalten.h"
#include "writeVectorToFile.h"
#include "constants.h"
#include "makeBackup.h"
#include "deleteAccount.h"
#include "timeframe.h"
#include "pressAnyKeyToContinue.h"
#include "userInputsNumber.h"

#include "account.h"
#include "FileStatusToOpen.h" 


// to switch on DEBUG_MSG see DebugMsg.h

int main() {
    makeBackup();
    std::vector<std::string> vOberkat;
    std::vector<std::string> vKat;
    std::vector<Account> vAccount;

    fillVector(vOberkat, oberkatFile);
    fillVector(vKat, katFile);
    fillAccountVector(vAccount, accountFile);

    clrScreen();
    showMainMenu();
    //std::cout << "READ: " << READ << " OVERWRITE: " << OVERWRITE << std::endl;
    std::string line;
    // getline doesn't ignore line breaks
    // getline returns the istream argument
    while( getline(std::cin, line) ) {
        if ( (line.empty()) || (line.size() > 1) || (!isdigit(line[0])) ){ 
            wrongInput();
            clrScreen();
            showMainMenu();
            continue;
        }
        const char input = (char)line[0];  // is this a good cast (ok casts are never friends)
        switch(input) {
            case '1': // eingaben Geldausgaben 
                      inputAccount(vAccount, vOberkat, vKat); 
                      writeVectorToFile(vAccount, tmpAccountFileToOverwrite); // overwrite
                      clrScreen();
                      showMainMenu();
                      break;
                      
            case '2': // Anzeigen aller Geldausgaben letzte Eingabe zuletzt 
                      sortAccountTimestampReverse(vAccount);
                      clrScreen();
                      showForPrint(vAccount, false);
                      pressAnyKeyToContinue();
                      clrScreen();
                      showMainMenu();
                      break;
                      
            case '3': // Loesche letzte  Eingabe (Geldeausgabe)
                      { // need new scope to define new variable i
                          sortAccountTimestampReverse(vAccount);
                          clrScreen();
                          showForDelete(vAccount);
                          std::cout << "\n Letzte Position wirklich loeschen";
                          std::cout << ":\n 1 Ja\n 0 Nein/abrechen\n";
                          unsigned i = userInputsNumber(1)+1; // starts counting with 0
                          if(i==1)
                              deleteLastAccount(vAccount);
                          else{
                              std::cout << "\n\t nicht geloescht!\n";
                              pressAnyKeyToContinue();
                          }
                          clrScreen();
                          showMainMenu();
                          break;
                      }

            case '4': // Loesche bestimmte Geldausgabe
                      { // need new scope to define new variable i
                      sortAccountTimestampReverse(vAccount);
                      clrScreen();
                      showForDelete(vAccount);
                      std::cout << "Welche Nummer soll geloescht werden: 0 Abbruch\n";
                      //std::cout << "\n" << vAccount.size() << std::endl;
                      unsigned int i = userInputsNumber(vAccount.size())+1;
                      if(i!=0)
                          deleteSomeAccount(vAccount, i);
                      clrScreen();
                      showMainMenu();
                      break;
                      }
                      
            case '5': // Anzeigen Geldausgaben Zeitraum 
                      clrScreen();
                      showTimeframe(vAccount, false);
                      pressAnyKeyToContinue();
                      clrScreen();
                      showMainMenu();
                      break;
                     
            case '6': // Druckdatei erzeugen  
                      clrScreen();
                      showTimeframe(vAccount, true);
                      clrScreen();
                      showMainMenu();
                      break;

            case '7': // Oberkategorien verwalten
                      oberkatVerwalten("Oberkategorien", vOberkat, OBERKAT_STRING_SIZE);
                      writeVectorToFile(vOberkat, oberkatFile);  // overwrite
                      showMainMenu();
                      break;
                      
            case '8': // Kategorien verwalten 
                      oberkatVerwalten("Unterkategorien", vKat, KAT_STRING_SIZE);
                      writeVectorToFile(vKat, katFile);
                      showMainMenu();
                      break;
                      
            case '9': // Speichern 
                      writeVectorToFile(vAccount, tmpAccountFileToOverwrite); 
                      clrScreen();
                      showMainMenu(); 
                      break;

            case '0': // Ende
                      {
                          clrScreen();
                          // Nein macht doch keinen Sinn da automatisch gespeichert wird,
                          // sobald man was eingibt....durchdenken
                          std::cout << "Soll gespeichert werden 0 oder 1 =Ja 9=Nein 7=Abbruch ? ";
                          std::string tmp;
                          getline(std::cin, tmp);
                          std::cout << tmp << std::endl;
                          if (tmp != "0" && tmp != "1" && tmp != "9" && tmp != "7"){ 
                              wrongInput();
                              clrScreen();
                              showMainMenu();
                              break;
                          }
                          if (tmp == "7"){
                              clrScreen();
                              showMainMenu();
                              break;
                          }
                          if (tmp == "J" || tmp == "0" || tmp == "1"){
                              writeVectorToFile(vAccount, tmpAccountFileToOverwrite);
                              std::cout << "\n\t gespeichert\n\t Bye bye Have a nice day!\n\n";
                          }
                          return 0;
                      }
            default:  assert("should never get here"); 
        }
    }
}


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

#include "account.h"
#include "timeStamp.h"
#include "printVector.h"
#include "clrScreen.h"
#include "constants.h"
#include "userInputsNumber.h"


Account::Account(std::string oberkat, std::string kat,
        std::string title, std::string day,
        std::string month, std::string year, double amount,
        timestamp time):oberkat_(oberkat), kat_(kat), title_(title), day_(day),
    month_(month), year_(year), amount_(amount), time_(time) {}

    std::string Account::getOberkat() const {
        return oberkat_;
    }

std::string Account::getKat() const {
    return kat_;
}

std::string Account::getTitle() const {
    return title_;
}

std::string Account::getDay() const {
    return day_;
}

std::string Account::getMonth() const {
    return month_;
}

std::string Account::getYear() const {
    return year_;
}

std::string Account::getDate() const {
    return day_ + month_ + year_;
}

double Account::getAmount() const {
    return amount_;
}

std::string Account::getTimestamp() const {
    return time_;
}


void Account::print() const {
    std::cout << "############method Account::print() ####################" << std::endl;
    std::cout << "Oberkategorie: " << oberkat_ << std::endl;
    std::cout << "Kategorie: " << kat_ << std::endl;
    std::cout << "Titel: " << title_ << std::endl;
    std::cout << "Datum: " << day_ << "." << month_ << "." << year_ << std::endl;
    std::cout << "Betrag: " << amount_ << std::endl;
    std::cout << "Zeitstempel: " << time_ << std::endl;
}

void showForDelete(std::vector<Account>& vecAccount){
    unsigned int counter = 0;
    unsigned int number = 1;
    for(const auto i : vecAccount){
        if(counter%20 == 0) {
            std::cout << " ";
            std::cout.width(4+1);
            std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
            std::cout << "Nr.";
            std::cout.width(OBERKAT_STRING_SIZE+1);
            std::cout << "Oberkategorie";
            std::cout.width(KAT_STRING_SIZE+1);
            std::cout << "Kategorie";
            std::cout.width(TITLE_SIZE+1);
            std::cout << "Titel";
            // standard fieldwidth
            std::cout.width(0);
            std::cout << "Datum      ";
            std::cout << "Preis\n";
            std::cout << " ===============================================";
            std::cout << "=============================================";
            std::cout << "==================\n";
            counter = 0;
        }
        std::cout << " ";
        std::cout.width(4+1);
        std::cout << number;
        std::cout.width(OBERKAT_STRING_SIZE+1);
        std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
        std::cout << i.getOberkat();
        std::cout.width(KAT_STRING_SIZE+1);
        std::cout << i.getKat();
        std::cout.width(TITLE_SIZE+1);
        std::cout << i.getTitle();
        // standard fieldwidth
        std::cout.width(0);
        std::cout << i.getDay() << "." << i.getMonth() << "." << i.getYear() << " ";
        std::cout.width(9+1);
        std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << i.getAmount();
        std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
        std::cout.width(0);
        std::cout << " " << i.getTimestamp() << "\n";
        counter++;
        number++;
    }
};

void showForPrint(std::vector<Account>& vecAccount, bool withAccountMonth){
    std::vector<std::string> vMonth = {
        "Januar", "Februar", "März", "April", "Mai", "Juni",
        "Juli", "August", "Septemeber", "Oktober", "November", "Dezember"};
    std::string sMonth= "";
    if(withAccountMonth)
        sMonth = " " + vMonth[stoi(vecAccount[0].getMonth())-1];
    unsigned int counter = 0;
    double sum = 0;
    std::map<std::string, double> mapOberKat;
    std::map<std::string, double> mapKat;
    std::cout << std::endl;
    for(const auto i : vecAccount){
        if(counter%61 == 0) {
            //std::cout << "\n\n\t" << vMonth[stoi(i.getMonth())] << "\n" << std::endl;
            std::cout << "\t";
            std::cout.width(OBERKAT_STRING_SIZE+2);
            std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
            std::cout << "Oberkategorie";
            std::cout.width(KAT_STRING_SIZE+2);
            std::cout << "Kategorie";
            std::cout.width(TITLE_SIZE+2);
            std::cout << "Titel";
            // standard fieldwidth
            std::cout.width(0);
            std::cout << "Datum            ";
            std::cout << "Preis\n";
            std::cout << "\t==============================================";
            std::cout << "===============================================\n";
            counter = 0;
        }
        std::cout << "\t";
        std::cout.width(OBERKAT_STRING_SIZE+2);
        std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
        std::cout << i.getOberkat();
        std::cout.width(KAT_STRING_SIZE+2);
        std::cout << i.getKat();
        std::cout.width(TITLE_SIZE+2);
        std::cout << i.getTitle();
        // standard fieldwidth
        std::cout.width(0);
        std::cout << i.getDay() << "." << i.getMonth() << "." << i.getYear() << "  ";
        std::cout << std::setiosflags(std::ios_base::right| std::ios::fixed) << std::setprecision(2) << std::setw(10) << i.getAmount() << "\n";
        counter++;
        sum += i.getAmount();
        mapOberKat[i.getOberkat()]=i.getAmount()+mapOberKat[i.getOberkat()];
        mapKat[i.getKat()]=i.getAmount()+mapKat[i.getKat()];
    }
    std::cout << "\n\n" << "\tSumme aller Ausgaben" << sMonth << ": " << sum << std::endl;
    std::cout <<           "\t--------------------";
    for(size_t i = 0; i < sMonth.length()+1; ++i)
        std::cout << "-";
    std::cout << "\n\n";
    for(auto const i : mapOberKat){
        std::cout << "\t" << i.first << "  " << i.second << std::endl;
    }
    std::cout << "\n";
    for(auto const i : mapKat){
        std::cout << "\t" << i.first << "  " << i.second << std::endl;
    }
};




void sortAccountOberkat(std::vector<Account>& vecAccount) {
    std::sort(vecAccount.begin(), vecAccount.end(), [](const Account& A, const Account& B){
            return A.getOberkat() < B.getOberkat();});
}

void sortAccountKat(std::vector<Account>& vecAccount) {
    std::sort(vecAccount.begin(), vecAccount.end(), [](const Account& A, const Account& B){
            return A.getKat() < B.getKat();});
}

void sortAccountDate(std::vector<Account>& vecAccount) {
    std::sort(vecAccount.begin(), vecAccount.end(), [](const Account& A, const Account& B){
            std::string dateA = A.getYear() + A.getMonth() + A.getDay();
            std::string dateB = B.getYear() + B.getMonth() + B.getDay();
            return std::stoi(dateA) > std::stoi(dateB);});
}

void sortAccountDateReverse(std::vector<Account>& vecAccount) {
    std::sort(vecAccount.begin(), vecAccount.end(), [](const Account& A, const Account& B){
            std::string dateA = A.getYear() + A.getMonth() + A.getDay();
            std::string dateB = B.getYear() + B.getMonth() + B.getDay();
            return std::stoi(dateA) < std::stoi(dateB);});
}




void sortAccountTimestampReverse(std::vector<Account>& vecAccount) {
    std::sort(vecAccount.begin(), vecAccount.end(), [](const Account& A, const Account& B){
            return std::stoul(A.getTimestamp()) < std::stoul(B.getTimestamp());});
}


/*
unsigned int userInputNumber(unsigned int size) {
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
            if(wahl < 1 || wahl > size){
                std::cout << "falsche Eingabe" << std::endl;
                continue;
            }
            break;
        }
        std::cin.clear();
        return wahl-1;
}
*/



void inputAccount(std::vector<Account>& vecAccount, std::vector<std::string>& vecOberKat,
        std::vector<std::string>& vecKat) {
    typedef std::string timestamp;
    std::string currentYear = getCurrentYear();
    const size_t sizeOfvecOberkat = vecOberKat.size();
    const size_t sizeOfvecKat = vecKat.size();
    std::string strYear;
    std::string oberkat, kat, title;
    std::string day, month, year; 
    double amount;
    std::string amountStr;
    unsigned int wahl;
    char c = 0;
    clrScreen();
    printVector(vecOberKat);
    std::cout << "oberkat: ";
    wahl = userInputsNumber(vecOberKat.size());
    oberkat = vecOberKat[wahl];
    oberkat.resize(OBERKAT_STRING_SIZE, ' ');
    
    clrScreen();
    printVector(vecKat);
    std::cout << "kat: ";
    wahl = userInputsNumber(vecKat.size());
    kat = vecKat[wahl];
    kat.resize(KAT_STRING_SIZE, ' ');
    
    std::cin.clear();
    std::cout << "title: ";
    while(1){
        std::cin.get(c);
        if(c=='\n'){
            title = "";
            break;
        }
        std::cin.putback(c);
        getline(std::cin, title);
        break;
    }

    title.resize(TITLE_SIZE, ' ');
    std::cout << "nur int day: ";
    while(1) {
        getline(std::cin, day);
        if (std::stoi(day) < 1 || std::stoi(day) > 31) {
            std::cout << "ff" << std::endl;
            continue;
        }
        if (std::stoi(day) > 0 && std::stoi(day) < 10)
            day = "0" + day;
        break;
    }
    std::cout << "month: ";
    while(1) {
        getline(std::cin, month);
        if (std::stoi(month) < 1 || std::stoi(month) > 12) {
            std::cout << "ff" << std::endl;
            continue;
        }
        if (std::stoi(month) > 0 && std::stoi(month) < 10)
            month = "0" + month;
        break;
    }
    // standarjahr in eine config-datei xml jason ???
    std::cout << "year(e.g.2012) (only hit enter for the current year " << currentYear << ": ";
    getline(std::cin, strYear);
    if (strYear.empty())
        year = currentYear;
    else
        year = strYear;
    std::cout << "year is now: " << year << std::endl; 
    std::cout << "amount: ";
    getline(std::cin, amountStr);
    std::size_t found = amountStr.find(',');
    if(found != std::string::npos) {
        amountStr[found]='.';
        amountStr.erase(found+3, std::string::npos);  // cut off after two digits 
                                                      // after the decimal point
    }
    amount = std::stod(amountStr);

    timestamp t = getTimeStamp(); 
    Account A(oberkat, kat, title, day, month, year, amount, t);
    vecAccount.push_back(A);
    //sortAccountOberkat(vecAccount);
    //sortAccountKat(vecAccount);
    // besser reverse
    //sortAccountDate(vecAccount);
    sortAccountDateReverse(vecAccount);
}


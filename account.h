#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>
#include "timeStamp.h"
class Account {
    public:
        typedef std::string timestamp;
        Account(std::string oberkat = "leer", std::string kat = "leer",
                std::string title = "leer", std::string day = "leer",
                std::string month = "leer", std::string year = "leer", 
                double amount = 0.0,
                timestamp time = "leer");
        void print() const;
        std::string getOberkat() const; 
        std::string getKat() const;
        std::string getTitle() const;
        std::string getDate() const;
        std::string getDay() const;
        std::string getMonth() const;
        std::string getYear() const;
        double getAmount() const;
        timestamp getTimestamp() const;
    private:
        std::string oberkat_;
        std::string kat_;
        std::string title_;
        std::string day_;
        std::string month_;
        std::string year_;
        double amount_;
        timestamp time_;
};
void showForDelete(std::vector<Account>& vecAccount);
void showForPrint(std::vector<Account>& vecAccount, bool withAccountMonth=false);
void sortAccountOberkat(std::vector<Account>& vecAccount);
void sortAccountKat(std::vector<Account>& vecAccount);
void sortAccountDate(std::vector<Account>& vecAccount);
void sortAccountDateReverse(std::vector<Account>& vecAccount);
void sortAccountTimestampReverse(std::vector<Account>& vecAccount);
void inputAccount(std::vector<Account>& vecAccount,
          std::vector<std::string>& vecOberKat,
          std::vector<std::string>& vecKat);

unsigned int userInputNumber(unsigned int size);
#endif // ACCOUNT_H_

#ifndef DELETE_ACCOUNT_H_
#define DELETE_ACCOUNT_H_

#include <string>
#include <vector>


#include "account.h"

void deleteSomeAccount(std::vector<Account>& vecAccount, size_t i);

void deleteLastAccount(std::vector<Account>& vecAccount);

#endif // DELETE_ACCOUNT_H_

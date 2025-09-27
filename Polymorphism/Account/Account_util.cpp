#include <iostream>
#include "Account_util.h"

void display ( const std::vector<Account *> &accounts )
    {
    for ( const auto iter:accounts )
        {
        std::cout << "===== Displaying Account details =====" << std::endl;
        std::cout << *iter << std::endl;
        }
    return;
    }
void deposit ( std::vector<Account *> &accounts, double amount)
    {
    for ( const auto iter:accounts )
        {
        std::cout << "===== Depositing in Account =====" << std::endl;
        iter->deposit (amount);
        }
    return;
    }
void withdraw ( std::vector<Account *> &accounts, double amount)
    {
    for ( const auto iter:accounts )
        {
        std::cout << "===== Withdrawing from Account =====" << std::endl;
        iter->withdraw (amount);
        }
    return;
    }
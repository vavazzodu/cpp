#include "Account.h"



std::ostream& operator<< ( std::ostream& os, const IFPrintable &obj )
    {
    obj.display ( os );
    return os;
    }

/* ------------- ACCOUNT ------------- */
Account::Account()
    {
    }
Account::Account( std::string str, double amount )
    : name{ str }, balance{ amount }
    {
    }
bool Account::withdraw( double amount )
    {
    if ( balance > amount )
        {
        balance -= amount;
        return true;
        }
    else
        {
        std::cout << "Account - Can not withdraw " << amount <<std::endl;
        return false;
        }
    }
bool Account::deposit( double amount )
    {
    balance += amount;
    return true;
    }
void Account::display ( std::ostream &os ) const
    {
    os << "[ Account: Name: "<<name<<" Balance: "<<balance<<" ]";
    }

/* ------------- SAVINGS ACCOUNT ------------- */
SavingsAccount::SavingsAccount()
    {
    }

SavingsAccount::SavingsAccount( std::string str, double amount, double per )
    : Account { str, amount }, int_rate{ per }
    {
    }
bool SavingsAccount::withdraw( double amount )
    {
    std::cout << "Money withdrawm from Savings Account" << std::endl;
    return Account::withdraw ( amount );
    }
bool SavingsAccount::deposit( double amount )
    {
    std::cout << "Money diposited in Savings Account" << std::endl;
    return Account::deposit ( amount );
    }
void SavingsAccount::display ( std::ostream &os ) const
    {
    os << "[ SavingsAccount: Name: "<<name<<" Balance: "<<balance<<" ]";
    }
/* ------------- CHECKING ACCOUNT ------------- */
CheckingAccount::CheckingAccount()
    {
    }

CheckingAccount::CheckingAccount( std::string str, double amount, double fee )
    : Account{ str, amount }, fee{ fee }
    {
    }
bool CheckingAccount::withdraw( double amount )
    {
    std::cout << "Money withdrawn from Checking Account" << std::endl;
    return Account::withdraw ( amount );
    }
bool CheckingAccount::deposit( double amount )
    {
    std::cout << "Money diposited in Checking Account" << std::endl;
    return Account::deposit ( amount );
    }
void CheckingAccount::display ( std::ostream &os ) const
    {
    os << "[ CheckingAccount: Name: "<<name<<" Balance: "<<balance<<" ]";
    }
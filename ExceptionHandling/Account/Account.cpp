#include "Account.h"
#include "IlligalBalance.h"
#include "InsufficientFunds.h"


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
    if ( balance < amount )
        {
        throw InsufficientFunds();    
        }
    balance -= amount;
    return true;
    }
bool Account::deposit( double amount )
    {
    if ( amount < 0 )
        {
        throw IlligalBalance();
        }    
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
    std::cout << "Money deposited in Savings Account" << std::endl;
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
#include "Account.h"

Account::Account()
{
    std::cout<<"Account default constructor\n";
}
Account::Account(double amount)
    : balance{amount}
{

}
Account::~Account()
{
    std::cout<<"Account destructor\n";
}

SavingsAccount::SavingsAccount()
{
    std::cout<<"SavingsAccount default constructor\n";
}
SavingsAccount::SavingsAccount(double amount, double per)
    : Account(amount), int_rate{per}
{
    
}
SavingsAccount::~SavingsAccount()
{
    std::cout<<"SavingsAccount destructor\n";
}

CheckingAccount::CheckingAccount()
{
    std::cout<<"CheckingAccount constructor\n";
}
CheckingAccount::CheckingAccount(double amount, double fee)
    : Account(amount), fee{fee}
{
    
}
CheckingAccount::~CheckingAccount()
{
    std::cout<<"CheckingAccount destructor\n";
}

TrustAccount::TrustAccount()
{
    std::cout<<"TrustAccount constructor\n";
}
TrustAccount::TrustAccount(double amount, double min_bal, double bonus)
    : Account(amount), min_bal{min_bal}, bonus{bonus}
{
    
}
TrustAccount::~TrustAccount()
{
    std::cout<<"TrustAccount destructor\n";
}
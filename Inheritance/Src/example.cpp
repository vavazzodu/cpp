#include "../Include/example.hpp"

Account::Account()
    : Account(0.0)
{
}
Account::Account(double balance)
    : balance{balance}
{
}
void Account::debit(double amount) { 
    if(balance > amount)
        balance -= amount;
    else
        cout<<"Insufficient funds"<<endl;
}
void Account::credit(double amount)
{ 
    balance+=amount;
}
ostream& operator<<(ostream &os, const Account &rhs)
{
    os<<"Account balance: "<<rhs.balance<<endl;
    return os;
}

Savings_account::Savings_account()
    : Savings_account(0.0,0.0)
{
}
Savings_account::Savings_account(double balance, double int_rate)
    : Account(balance), int_rate(int_rate)
{
}
void Savings_account::credit(double amount)
{
    amount = amount+(amount*int_rate/100);
    balance = balance+amount;
}
ostream& operator<<(ostream &os, const Savings_account &rhs)
{
    os<<"Savings_account balance: "<<rhs.balance<<endl;
    return os;
}

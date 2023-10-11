#include<iostream>
using namespace std;

class Account {
    friend ostream& operator<<(ostream &os, const Account &rhs);
protected:
    double balance;
public:
    Account();
    Account(double balance);
    void debit(double amount); 
    void credit(double amount);
};

class Savings_account : public Account {
    friend ostream& operator<<(ostream &os, const Savings_account &rhs);
protected:
    double int_rate;
public:
    Savings_account();
    Savings_account(double balance, double int_rate);
    void credit(double amount);
};


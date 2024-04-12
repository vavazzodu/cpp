#ifndef __ACCOUNT__
#define __ACCOUNT__
#include <iostream>

class Account {
    private:
        double balance;
    public:
        Account();
        Account(double amount);
        virtual ~Account();
        virtual void withdraw(double amount)
        {
            std::cout<<"Account: withdraw\n";
        }
};

class SavingsAccount : public Account {
    private:
        double int_rate;
    public:
        SavingsAccount();
        SavingsAccount(double amount, double per);
        virtual ~SavingsAccount();
        virtual void withdraw(double amount)
        {
            std::cout<<"SavingsAccount: withdraw\n";
        }
};
class CheckingAccount : public Account {
    private:
        double fee;
    public:
        CheckingAccount();
        CheckingAccount(double amount, double fee);
        virtual ~CheckingAccount();
        virtual void withdraw(double amount)
        {
            std::cout<<"CheckingAccount: withdraw\n";
        }
};
class TrustAccount : public Account {
    private:
        double min_bal;
        double bonus;
    public:
        TrustAccount();
        TrustAccount(double amount, double min_bal, double bonus);
        virtual ~TrustAccount();
        virtual void withdraw(double amount)
        {
            std::cout<<"TrustAccount: withdraw\n";
        }
};
#endif

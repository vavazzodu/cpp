#ifndef __ACCOUNT__
#define __ACCOUNT__
#include <iostream>
class IFPrintable
    {
    friend std::ostream& operator<< ( std::ostream& os, const IFPrintable &obj );
    public:
        virtual void display ( std::ostream &os ) const = 0;
        virtual ~IFPrintable() = default;
    };

class Account : public IFPrintable
    {
    protected:
        std::string name;
        double balance;
    public:
        Account();
        Account(std::string str, double amount);
        
        virtual bool withdraw( double amount ) = 0;
        virtual bool deposit( double amount ) = 0;
        virtual ~Account() = default;
        virtual void display ( std::ostream &os ) const override ;
    };

class SavingsAccount : public Account {
    private:
        double int_rate;
    public:
        SavingsAccount();
        SavingsAccount(std::string str, double amount, double per);
        virtual ~SavingsAccount() = default;
        virtual bool withdraw( double amount ) override;
        virtual bool deposit( double amount ) override;
        virtual void display ( std::ostream &os ) const override ;
};
class CheckingAccount : public Account {
    private:
        double fee;
    public:
        CheckingAccount();
        CheckingAccount( std::string str, double amount, double fee);
        virtual ~CheckingAccount() = default;
        virtual bool withdraw( double amount ) override;
        virtual bool deposit( double amount )override;
        virtual void display ( std::ostream &os ) const override ;
};

#endif

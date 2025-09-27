/* Includes */
#include <iostream>
using namespace std;
class IFPrintable 
    {
    public:
        friend ostream& operator << ( ostream &os, IFPrintable &obj );
        virtual void Print ( ostream &os ) = 0;
        virtual ~IFPrintable() 
            {
            }
    };
ostream& operator << ( ostream &os, IFPrintable &obj)
    {
        obj.Print( os );
        return os;
    }
class Account : public IFPrintable
    {
    public:
        virtual void Print ( ostream &os ) override
            {
                cout << "This is Account class" << endl;
                return;
            }
    };
class CurrentAccount :  public Account
    {
    public:
        virtual void Print ( ostream &os ) override
            {
                cout << "This is Current Account class" << endl;
                return;
            }
    };
class SavingsAccount :  public Account
    {
    public:
        virtual void Print ( ostream &os ) override
            {
                cout << "This is Savings Account class" << endl;
                return;
            }
    };
int main()
    {
        Account *obj = new CurrentAccount();
        cout << *obj << endl;     //This is Current Account class
        delete (obj);
        obj = new SavingsAccount();
        cout << *obj << endl;     //This is Savings Account class
        delete (obj);
        return 0;
    }
#include "Account.h"

int main()
{
    // Account a {1000};
    // SavingsAccount b{1000, 5};
    // CheckingAccount c{1000, 2.5};
    // TrustAccount d{1000, 200, 50};

    Account *p1 = new Account{1000};
    Account *p2 = new SavingsAccount{1000, 5};
    Account *p3 = new CheckingAccount{1000, 2.5};
    Account *p4 = new TrustAccount{1000, 200, 50};
    p1->withdraw(100);
    p2->withdraw(100);
    p3->withdraw(100);
    p4->withdraw(100);

    delete(p1);
    delete(p2);
    delete(p3);
    delete(p4);
    return 0;
}
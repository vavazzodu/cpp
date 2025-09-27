#include "Account.h"
#include "Account_util.h"
int main()
{
    // Account a {1000};
    // SavingsAccount b{1000, 5};
    // CheckingAccount c{1000, 2.5};
    // TrustAccount d{1000, 200, 50};
    Account *p2 = new SavingsAccount{ "Karan", 1000, 5};
    Account *p3 = new CheckingAccount{ "Krishna", 1000, 2.5};
    
    std::vector <Account *> accPtr = {p2, p3};
    
    deposit ( accPtr, 100 );
    display ( accPtr );
    withdraw ( accPtr, 50 );
    display ( accPtr );
    /* If we do not define virtual destructor the following
     * will call Account class (Base class) destructor 4 times
     * and we will have memory leak */ 
    delete(p2);
    delete(p3);
    return 0;
}

#include "Account.h"
#include "Account_util.h"
#include <memory>

int main()
{
/* Simple execution */
/*  Account a {1000};
    SavingsAccount b{1000, 5};
    CheckingAccount c{1000, 2.5};
    TrustAccount d{1000, 200, 50}; */

/* Dynamic polymorphism via bass class pointer */
/*  Account *p2 = new SavingsAccount{ "Karan", 1000, 5};
    Account *p3 = new CheckingAccount{ "Krishna", 1000, 2.5};
    
    std::vector <Account *> accPtr = {p2, p3};
    
    deposit ( accPtr, 100 );
    display ( accPtr );
    withdraw ( accPtr, 50 );
    display ( accPtr );
    // If we do not define virtual destructor the following
    // will call Account class (Base class) destructor 4 times
    // and we will have memory leak
    delete(p2);
    delete(p3); 
*/
/* Smart pointer where we don't need to handle new/delete */
/*
    std::unique_ptr<Account> ptr1 = std::make_unique<SavingsAccount>("Karan", 1000, 5);
    std::cout << *ptr1 << std::endl;
    std::unique_ptr<Account> ptr2 = std::make_unique<CheckingAccount>("Krishna", 1200, 2.5);
    std::cout << *ptr2 << std::endl;
    ptr1->deposit(100);
    ptr2->deposit(500);
    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;
    // Copy or assignment is not allowed with smart pointers
    std::unique_ptr<Account> ptr3;
    //ptr3 = ptr1;  //This line will give an error

    // We can move the owner ship of the ptr1 to ptr3
    ptr3 = std::move (ptr1);
    std::cout << *ptr3 << std::endl;
    // once the ownership is transferred, ptr1 will be NULL
    if( ptr1 == NULL )
        std::cout << "Ptr1 is NULL" << std::endl;
*/
    /* Now we will use a vector with smart pointers */
    //accounts is a vector which contains some unique pointers, pointing to Account class
    std::vector < std::unique_ptr < Account > > accounts;
    accounts.push_back ( std::make_unique<SavingsAccount> ("Karan", 1000, 5) );
    accounts.push_back ( std::make_unique<CheckingAccount> ("Krishna", 1500, 5) );
    // we need to use &acc here as copying is not allowed with smart pointers.
    for ( auto &acc:accounts)
    {
        std::cout << *acc << std::endl;
    }


    return 0;
}

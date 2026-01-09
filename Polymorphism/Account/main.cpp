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
/*
    // Accounts is a vector which contains some unique pointers, pointing to Account class
    std::vector < std::unique_ptr < Account > > accounts;
    accounts.push_back ( std::make_unique<SavingsAccount> ("Karan", 1000, 5) );
    accounts.push_back ( std::make_unique<CheckingAccount> ("Krishna", 1500, 5) );
    // we need to use &acc here as copying is not allowed with smart pointers.
    for ( auto &acc:accounts)
    {
        std::cout << *acc << std::endl;
    }
*/
/*
    // shared_pointer example
    std::shared_ptr<int> ptr { new int{100} };
    std::cout <<"ptr: "<<*ptr << std::endl; //100

    std::cout << "use count ptr: "<<ptr.use_count() << std::endl;  //1
    std::shared_ptr<int> ptr1 {ptr};
    std::cout <<"ptr1: "<<*ptr1 << std::endl; //100
    std::cout <<"use count ptr1: "<<ptr1.use_count() << std::endl; //2
    ptr.reset(); //ptr is resetted and nulled, not it is not pointing to any location
    std::cout << "use count ptr: "<<ptr.use_count() << std::endl;  //0
    std::cout <<"use count ptr1: "<<ptr1.use_count() << std::endl; //1
*/
    // make shared method and vectors
    std::shared_ptr<Account> acc1 = std::make_shared<SavingsAccount> ("Karan", 1000, 5);
    std::shared_ptr<Account> acc2 = std::make_shared<CheckingAccount> ("Krishna", 1200, 2.5);
    std::cout <<"use count acc1: "<<acc1.use_count() << std::endl; //1
    
    std::vector < std::shared_ptr<Account> > accounts;
    // push_back() works as shared pointers can be copied.
    accounts.push_back ( acc1 );
    accounts.push_back ( acc2 );
    // Since copy of acc1 is happened in the accounts, now two shared pointers are pointing at the heap
    std::cout <<"use count acc1: "<<acc1.use_count() << std::endl; //2

    for ( const auto &acc: accounts)
    {
        std::cout << *acc << std::endl;
    }
    return 0;
}

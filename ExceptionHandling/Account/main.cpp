/*
 * compile: g++ -Wall -std=c++17 Account.cpp Account_util.cpp main.cpp -o exe
 */
#include "Account.h"
#include <memory>

int main()
{
    Account *ptr1 = new SavingsAccount {"Jack", 1000, 7 };
    try 
    {
        ptr1->deposit ( 2000 );
        std::cout << *ptr1 << std::endl;
        ptr1->withdraw ( 2000 );
        std::cout << *ptr1 << std::endl;
    }
    catch ( std::exception &ex )
    {
        std::cout << ex.what() << std::endl;
    }
    std::cout<< "Bye\n";
    return 0;
}

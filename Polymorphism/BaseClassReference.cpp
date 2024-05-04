#include "./Account.h"

void do_withdraw(Account &account, double amount)
    {
        std::cout << "Calling withdraw() via do_withdraw()\n";
        account.withdraw(amount);  // Calls SavingsAccount.withdraw()
    }
int main()
    {
        //Account a1;
        //a1.withdraw(100); //Calls Account.withdraw()

        //Account &ref = a1;
        //ref.withdraw(100); //Calls Account.withdraw()

        //SavingsAccount s1;
        //Account &ref1 = s1;
        //ref1.withdraw(100); //Calls SavingsAccount.withdraw()

        SavingsAccount s2;
        do_withdraw(s2, 200);

        return 0;
    }


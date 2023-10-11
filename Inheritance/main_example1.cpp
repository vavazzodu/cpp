#include "./Include/example.hpp"

int main()
{
/*    cout<<"Account Information\n";
    cout<<"===================\n";
    Account a1(1000.0);
    cout<<a1<<endl;
    a1.credit(500);
    cout<<"Rs.500 credited\n";
    cout<<a1<<endl;
    a1.debit(800);
    cout<<"Rs.800 debited\n";
    cout<<a1<<endl; */
    
    cout<<"Savings Account Information\n";
    cout<<"============================\n";
    Savings_account s1(300, 5);
    cout<<s1<<endl;
    s1.credit(300);
    cout<<"Rs.300 credited\n";
    cout<<s1<<endl;
    s1.debit(215);
    cout<<"Rs.215 debited\n";
    cout<<s1<<endl;
    s1.debit(500);
    cout<<s1<<endl;

}

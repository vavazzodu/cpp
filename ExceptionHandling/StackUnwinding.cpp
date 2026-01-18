#include <iostream>

//forward declaration
void func_a();
void func_b();
void func_c();

void func_a()
{
    std::cout << "Starting func_a()\n";
    func_b();
    std::cout << "Ending func_a()\n";
}
void func_b()
{
    std::cout << "Starting func_b()\n";
    //try
    //{
        func_c();
    //}
    // catch ( int &ex )
    // {
    //     std::cout << "Caught in func_b()\n";
    // }
    std::cout << "Ending func_b()\n";    
}
void func_c()
{
    std::cout << "Starting func_c()\n";
    /* When we throw this exception, this function will be removed from 
     * the stack and last cout will not be executed. The throw will look
     * for handler in the func_b(), If not found that will also be removed
     * from the stack and the cout after func_c() wont execute. Now, handler
     * will be looked into the func_a() and same process repeats.*/
    throw 0;
    std::cout << "Ending func_c()\n";
}
int main()
{
    std::cout << "Starting main()\n";
    try
    {
        func_a();
    }
    catch (...)
    {
        std::cout <<"Caught default throw in the main()\n" ;
    }
    std::cout << "Ending main()\n";
    return 0;
}
// User defined exception class

#include <iostream>
#include <string>

class NegativeValueException
{
};
class DivideByZeroException
{
};

double cal_kmph( int km, int hr )
{
    /* If hr is zero we will throw an exception 0 (int)
     * If any one km or hr is negative we will throw a string exception
     * In any case the logic to calculate kmph wont execute.
     */
    if ( hr == 0)
    {
        throw DivideByZeroException();
    }
    if ( km < 0 || hr < 0)
    {
        throw NegativeValueException();
    }
    /* If exerything is ok, calculate the kmph and return */
    return static_cast<double>(km)/hr;
}
int main()
{
    int km, hr;
    double kmph;
    std::cout << "Enter the km value: ";
    std::cin>>km;
    std::cout << "Enter the hour value: ";
    std::cin>>hr;
    /* putting a code block which can have a problem under the try block 
     * In cal_kmph() we are throwing an exception, If exception is thrown
     * the code to print the kmph value will not execute and the catch block
     * will be executed. */
    try
    {
        kmph = cal_kmph( km, hr );
        std::cout << "Kmph: "<<kmph<<std::endl;
    }
    catch( DivideByZeroException &obj )
    {
        std::cerr <<"Error: Sorry, can not divided by zero"<< std::endl;
    }
    catch( NegativeValueException &obj )
    {
        std::cerr <<"Error: Sorry, one of your value is negative"<< std::endl;
    }
    
    return 0;
}
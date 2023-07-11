/*
 * =====================================================================================
 *
 *    Filename:  main.cpp
 *    Description:  main function call
 *    Author:  Karan Raval (), karanraval72@yahoo.com
 *
 * =====================================================================================
 */

#include "MyString.h"
using namespace std;
int main()
{
    // - operator overloading
    /*MyString karan{"KARAN"};
    MyString raval{"Raval"};
    std::cout<<"karan: ";
    karan.display();
    std::cout<<"raval: ";
    raval.display();
    MyString a{karan};
    std::cout<<"a: ";
    a.display();
    MyString b;
    b = raval;
    std::cout<<"b: ";
    b.display();
    b = -b;
    std::cout<<"b: ";
    b.display();*/
    
    /*MyString a{"Karan"};
    MyString b{"raval"};
    a.display();
    b.display();
    MyString c = a + "'s surname is";
    c.display();
    b = +b;
    MyString d = c + " " + b ;
    d.display();*/

    MyString first{"Karan"};
    MyString middle{"Rajeshbhai"};
    MyString last;

    cout <<"Enter the last name:\n";
    cin >>last;
    cout << first <<" "<<middle<<" "<<last<<std::endl;
    return 0;
}


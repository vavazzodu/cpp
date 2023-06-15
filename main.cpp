#include "MyString.h"
using namespace std;
int main()
{
    //Assignment operator overloading
    /*MyString a{"Karan"};
    MyString b;
    b = a;
    cout<<"Printing a\n";
    a.display();
    cout<<"Printing b\n";
    b.display();*/

    //Move operator overloading
    /*MyString a;
    a = MyString("Karan");
    cout<<"Printing a\n";
    a.display();
    MyString b;
    b = "Khal";
    cout<<"Printing b\n";
    b.display();*/

    // - operator overloading
    MyString karan{"KARAN"};
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
    b.display();
    return 0; 
}


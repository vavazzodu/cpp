#include "MyString.h"
using namespace std;
int main()
{
	MyString a{"Hello"};
    MyString b;
    b = a;
    cout<<"Printing b\n";
    b.display();
    return 0;
}


#include <iostream>
#include <cstring>
#include <string>

class MyString {
private:
    char *str;
public:
    MyString();
    MyString(const char *);
    MyString(const MyString *);
    MyString (const MyString &src);  //copy constructor
    ~MyString();
    //Overloaded operators//
    MyString & operator=(const MyString &rhs);
    MyString & operator=(MyString &&rhs);
    //Unary - operator overloading, makes string lowercase
    MyString operator-()const;
    void display() const ;
};

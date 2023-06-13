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
    ~MyString();
    MyString & operator=(const MyString &rhs);
    MyString & operator=(MyString &&rhs);
    void display() const ;
};

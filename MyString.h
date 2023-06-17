#include <iostream>
#include <cstring>
#include <string>

class MyString {
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend MyString operator+(const MyString &obj);
private:
    char *str;
public:
    MyString();
    MyString(const char *);
    MyString(const MyString *);
    MyString (const MyString &src);
    ~MyString();
    /* Member method: operator overloading */
        // Assignment operator //
    MyString & operator=(const MyString &rhs);
        // Move operator //
    MyString & operator=(MyString &&rhs);
        // Unary - operator overloading //
    MyString operator-()const;
    /* Display function */
    void display() const ;
};

/*
 * =====================================================================================
 *
 *    Filename: MyString.h
 *    Description:  Class declarations
 *    Author:  Karan Raval (), karanraval72@yahoo.com
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>
#include <string>

class MyString {
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend MyString operator+(const MyString &obj);
    friend std::ostream& operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream& operator>>(std::istream &is, MyString &rhs);
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

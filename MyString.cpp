#include "MyString.h"

MyString::MyString()
    :str(nullptr)
    {
        std::cout<<"Empty Constructor\n";
        str = new char[1];
        *str = '\0';
    }
MyString::MyString(const char *src)
    :str(nullptr)
    {
        std::cout<<"Overloaded Constructor\n";
        if(src == nullptr)
        {
            str = new char[1];
            *str = '\0';
        }
        else
        {
            delete []str;
            str = new char [std::strlen(src)+1];
            std::strcpy(str, src);
        }
    }
MyString::MyString(const MyString *src)
{
    std::cout<<"Copy constructor\n";
    str = new char [std::strlen(src->str)+1];
    std::strcpy(str, src->str);
}
MyString::~MyString()
{
    std::cout<<"Destructor\n";
    delete []str;
}
MyString & MyString::operator=(const MyString &rhs)
{
    std::cout<<"= operator overloading\n";
    if(this == &rhs)
        return *this;
    else
    {
        delete []this->str;
        this->str = new char [std::strlen(rhs.str)+1];
        std::strcpy(this->str, rhs.str);
        return *this;
    }
}
MyString & operator=(MyString &&rhs)
{

}

void MyString::display() const
{
    std::cout<<"String: "<<str<<std::endl;
}


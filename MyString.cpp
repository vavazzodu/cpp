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
MyString::MyString (const MyString &src)  //copy constructor
{
	std::cout<<"In copy constructor\n";
	str = new char[std::strlen(src.str)+1];
	std::strcpy(str, src.str);
}
MyString::~MyString()
{
    std::cout<<"Destructor"<<std::endl;
    delete []str;
}
MyString & MyString::operator=(const MyString &rhs)
{
    std::cout<<"Assignment operator overloading\n";
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
MyString & MyString::operator=(MyString &&rhs)
{
    std::cout<<"Move operator overloading\n";
    //If the same object is assigned
    if(this == &rhs)
        return *this;
    delete []str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}
MyString MyString::operator-()const
{
    std::cout<<"In unary - operator overloading\n";
    char *buff;
    size_t i;
    buff = new char [strlen(this->str) + 1];
    std::strcpy(buff,this->str);
    for(i=0;i<std::strlen(buff); i++)
	buff[i] =  std::tolower(buff[i]);
    MyString temp {buff};
    delete []buff;
    return temp;
}
void MyString::display() const
{
    std::cout<<"String: "<<str<<std::endl;
}


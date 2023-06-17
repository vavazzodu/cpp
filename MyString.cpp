#include "MyString.h"

//Empty constructor//
MyString::MyString()
    :str(nullptr)
    {
        std::cout<<"Empty Constructor\n";
        str = new char[1];
        *str = '\0';
    }
//Overloaded constructor//
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
//Copy constructor//
MyString::MyString (const MyString &src)
    {  
	std::cout<<"In copy constructor\n";
	str = new char[std::strlen(src.str)+1];
	std::strcpy(str, src.str);
    }
//Destructor//
MyString::~MyString()
    {
        std::cout<<"Destructor"<<std::endl;
        delete []str;
    }
//Member method: assignment operator overloading//
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
//Member method: Move operator overloading //
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
//Member method: Unary - operator overloading//
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
//Display function for printing the op //
void MyString::display() const
    {
        std::cout<<str<<std::endl;
    }
// Global method: == operator overloadign (Equality check)
bool operator==(const MyString &lhs, const MyString &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}
// Global method: Binary + operator overloading (Concatination)
MyString operator+(const MyString &lhs, const MyString &rhs)
{
    char *buff = new char [std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff,lhs.str);
    std::strcat(buff,rhs.str);
    MyString temp{buff};
    delete []buff;
    return temp;
}
// Global method: Unary + operator overloading (Make upper case)
MyString operator+(const MyString &obj)
{
    char *buff = new char [std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for(size_t i =0; i<std::strlen(buff); i++)
        buff[i] = std::toupper(buff[i]);
    MyString temp {buff};
    delete []buff;
    return temp;
}

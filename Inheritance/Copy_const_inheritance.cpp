#include <iostream>
using namespace std;

class Base {
    public:
        int value;
        Base();
        Base(int num);
        Base(const Base &obj);
        Base& operator=(const Base &rhs);
        ~Base();
};
class Derived:public Base {
    public:
        int double_value;
        Derived();
        Derived(int num);
        Derived(const Derived &obj);
        Derived& operator=(const Derived &rhs);
        ~Derived();
};
Base::Base()
    : value{0}
{
    cout<<"Empty base constructor"<<endl;
}
Base::Base(int num)
    : value{num}
{
    cout<<"Single arg base constructor"<<endl;
}
Base::Base(const Base &obj)
    :value{obj.value}
{
    cout<<"Base copy constructor"<<endl;
}
Base& Base::operator=(const Base &rhs)
{
    cout<<"Base assignment operator overloading"<<endl;
    if(this != &rhs)
        value = rhs.value;
    return *this;
}
Base::~Base()
{
    cout<<"Base destructor"<<endl;
}

Derived::Derived()
    :Base(), double_value{0}
{
    cout<<"Empty derived constructor"<<endl;
}
Derived::Derived(int num)
    :Base(num), double_value{2*num}
{
    cout<<"Single arg Derived constructor"<<endl;
}
Derived::Derived(const Derived &obj)
    :Base(obj), double_value{obj.double_value}
{
    cout<<"Derived copy constructor"<<endl;
}
Derived& Derived::operator=(const Derived &rhs)
{
    cout<<"Derived assignment operator overloading"<<endl;
    if(this != &rhs)
    {
        Base::operator=(rhs);
        double_value = rhs.double_value;
    }
    return *this;
}
Derived::~Derived()
{
    cout<<"Derived destructor"<<endl;
}

int main()
{
    Derived d1(100);
    Derived d2(d1);
    d2 = d1;
    cout<<"d1= "<<d1.double_value<<" d2= "<<d2.double_value<<endl;
    cout<<"d1.value= "<<d1.value<<" d2.value= "<<d2.value<<endl;
}

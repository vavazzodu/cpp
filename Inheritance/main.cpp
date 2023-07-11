#include <iostream>
using namespace std;

class Base { 
public:
    int val;
    Base();
    Base(int x);
    ~Base();
};

class Derived:public Base {
public:
    int doub_val;
    Derived();
    Derived(int x);
    ~Derived();
};

Base::Base()
    :val{0} {
        cout<<"In no-arg Base class\n";
}
Base::Base(int x)
    :val{x} {
        cout<<"In int-arg Base class\n";
}
Base::~Base(){
    cout<<"Base destructor\n";
}


Derived::Derived()
    :Base(), doub_val{0} {
        cout<<"In no-arg Derived class\n";
}
Derived::Derived(int x)
    :doub_val{2*x}, Base(x) {
        cout<<"In int-arg Derived class\n";
}
Derived::~Derived(){
        cout<<"Derived destructor\n";
}

int main()
{
    Derived d{100};
    cout<<"Derived val="<<d.doub_val<<endl;  
}

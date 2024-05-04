#include <iostream>

class Base
    {
    public:
        virtual ~Base() { }
        virtual void say_hello() const
            {
                std::cout << "Hello - This is Base class\n";
            }
    };
class Derived final: public Base
    {
        public:
            virtual ~Derived() { }
            virtual void say_hello() const override
            {
                std::cout << "Hello - This is Derived class\n";
            }
    };
/* The below code will give error as we are trying to inherit Derived1 from Dervied, 
 * which is made 'final' 
class Derived1 : public Derived
    {
        public:
            virtual ~Derived1(){}
            virtual void say_hello() const
            {
                std::cout<< "Hello - This is Derived1 class\n";
            }
    };*/
int main()
    {
        Base *ptr1 = new Base();
        ptr1->say_hello();    //Hello - This is Base
        Derived *ptr2 = new Derived();
        ptr2->say_hello();    //Hello - This is Derived
        Base *ptr3 = new Derived();
        ptr3->say_hello();
    }

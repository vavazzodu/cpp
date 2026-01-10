#include<iostream>
#include<memory>

class Test
{
    public:
    int data;

    Test() { std::cout << "This is normal constructor" << std::endl; }
    Test(int num): data{num} { std::cout << "This is parameterized constructor" << std::endl; }
    ~Test() { std::cout << "This is Test destructor for data:" << data << std::endl; }
};

void my_deleter ( Test *raw_pointer)
{
    std::cout << "This is my deleter function" << std::endl;
    delete raw_pointer;
}
int main()
{
    std::cout << "\tThis is with deleter function" << std::endl;
    {
        std::shared_ptr<Test> ptr{ new Test{100}, my_deleter };
    }
    std::cout << "\tThis is with lamda expression" << std::endl;
    std::shared_ptr<Test> ptr{ new Test{1000}, [] ( Test *raw_pointer)
                {
                    std::cout << "This is lamda expression deallocation" << std::endl;
                    delete raw_pointer;
                } };

    return 0;
}
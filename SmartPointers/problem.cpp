#include<iostream>
#include<memory>
#include<vector>

class Test
{
    private:
    int data;
    public:
    Test() { std::cout << "This is basic constructor" << std::endl; }
    Test(int num): data{num} { std::cout << " This is constructor with argument" << std::endl; }
    ~Test() { std::cout << " Destructor Test data: " << data << std::endl; }
    int get_data() const { return data; }
};

std::unique_ptr < std::vector < std::shared_ptr<Test> > > make()
{
    return std::make_unique < std::vector < std::shared_ptr<Test> > >();
}

void fill ( std::vector < std::shared_ptr<Test> > &ptr, int n )
{
    for ( auto i = 0; i<n; i++ )
    {
        int lvnum;
        std::cout << "Enter the data for ["<<i<<"] position" << std::endl;
        std::cin >> lvnum;
        ptr.push_back ( std::make_shared<Test> (lvnum) );
    }
    return;
}

void display ( const std::vector < std::shared_ptr<Test> > &ptr )
{
    std::cout << "=========================" << std::endl;
    int lvcount = 0;
    for ( auto i:ptr )
    {
        std::cout << "Data[" << lvcount << "] is " << ptr[lvcount]->get_data() << std::endl;
        lvcount++;
    }
}
int main()
{
    std::unique_ptr < std::vector < std::shared_ptr<Test> > > vec_ptr;
    vec_ptr = make();
    int num;
    std::cout << "How many data points you want to add?" << std::endl;
    std::cin >> num;
    fill ( *vec_ptr, num );
    display( *vec_ptr );
    return 0;
}
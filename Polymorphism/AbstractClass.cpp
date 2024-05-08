#include <iostream>

class Shape //Abstract class as it contains pure virtual function
    {
        public:
            virtual void draw() = 0;  //Pure virtual function
            virtual void rotate() = 0; //Pure virtual function
            virtual ~Shape() { }
    };
class OpenShape : public Shape {  //Abstract class
    };
class CloseShape : public Shape { //Absract class
    };

class Line : public OpenShape  //Concrete class as we are overriding the functions
    {
        public:
            virtual void draw() override
                {
                    std::cout <<"Drawing line...\n";
                }
            virtual void rotate() override
                {
                    std::cout <<"Rotating line...\n";
                }
    };
class Circle : public CloseShape  //Concrete class as we are overriding the functions
    {
        public:
            virtual void draw() override
                {
                    std::cout <<"Drawing circle...\n";
                }
            virtual void rotate() override
                {
                    std::cout <<"Rotating circle...\n";
                }
    };
class Square : public CloseShape  //Concrete class as we are overriding the functions
    {
        public:
            virtual void draw() override
                {
                    std::cout <<"Drawing square...\n";
                }
            virtual void rotate() override
                {
                    std::cout <<"Rotating square...\n";
                }
    };

int main()
    {
        /*  Error as we can not create Abstract class object
        Shape obj;
        obj.draw();
        
        Shape *ptr;
        ptr = new Shape;
        ptr->draw(); 
        
        OpenShape obj;
        obj.draw(); */

        /* No error code */
        Circle obj;
        obj.draw();

        Shape *ptr;
        ptr = new Square;
        ptr->rotate();

        OpenShape *ptr1;
        ptr1 = new Line;
        ptr1->draw();
        return 0;
    }

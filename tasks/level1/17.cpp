/*Introduce the concept of exception handling within an inheritance hierarchy.
Create a base class Shape with an area calculation method that might throw an exception 
(e.g., if the shape's dimensions are not set). Then, derive two classes from it: 
Circle and Rectangle. Implement the area calculation method for each derived class to 
handle or throw exceptions as appropriate.*/

#include <iostream>
#include <stdexcept>

class Shape
{
    public:
    virtual double area() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
    private:
        int R;
    public:
        Circle(int x)
        {
            if(x <= 0)
            {
                throw std::invalid_argument("Invalid argument: ");
            }
            else
            {
                R = x;
            }
        }
        double area()
        {
            return 3.14 * R * R;
        }
        ~Circle() = default;
};

class Rectangle : public Shape
{
    private:
        int a;
        int b;
    public:
        Rectangle(int a1,int b1)
        {
            if(a1 <= 0 || b1 <= 0)
            {
                throw std::invalid_argument("Invalid argument: ");
            }
        }
        
        double area()
        {
            return a * b;
        }    
        ~Rectangle() = default;
};

void print(Shape* ptr)
{
    std::cout << ptr -> area();
}

int main()
{
    Shape* ptr = new Circle(4);
    print(ptr);
    std::cout << std::endl;
    delete ptr;
    ptr = new Rectangle(3,9);
    print(ptr);
    std::cout << std::endl;
}   

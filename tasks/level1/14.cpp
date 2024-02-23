/*Create a base class Shape with a method to calculate the area and derive two 
classes from it: Circle and Rectangle. Implement the area calculation method for 
each derived class.*/

#include <iostream>

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
        Circle(int x) : R(x) {}
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
        Rectangle(int a1,int b1) : a(a1) , b(b1) {}
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

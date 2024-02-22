/*Create a base class Shape with a method to calculate the area and derive two 
classes from it: Circle and Rectangle. Implement the area calculation method for 
each derived class.*/

#include <iostream>

class Shape
{
    double area();
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
};

int main()
{

}

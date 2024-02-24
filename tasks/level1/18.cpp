#include <iostream>

template<typename T>
class Shape 
{
public:
    virtual T area() const = 0; 
};


template<typename T>
class Circle : public Shape<T> 
{
private:
    T R;
public:
    Circle(T r) : R(r) {}
    T area() const override 
    {
        return 3.14 * R * R;
    }
};


template<typename T>
class Rectangle : public Shape<T> 
{
private:
    T a;
    T b;
public:
    Rectangle(T a1, T b1) : a(a1), b(b1) {}
    T area() const override 
    {
        return a * b;
    }
};

int main() 
{
    Circle<int> intCircle(5);
    Circle<float> floatCircle(5.5f);
    Circle<double> doubleCircle(5.5);

    Rectangle<int> intRect(4, 5);
    Rectangle<float> floatRect(4.5f, 5.5f);
    Rectangle<double> doubleRect(4.5, 5);

    std::cout << "Area of intCircle: " << intCircle.area() << std::endl;
    std::cout << "Area of floatCircle: " << floatCircle.area() << std::endl;
    std::cout << "Area of doubleCircle: " << doubleCircle.area() << std::endl;

    std::cout << "Area of intRect: " << intRect.area() << std::endl;
    std::cout << "Area of floatRect: " << floatRect.area() << std::endl;
    std::cout << "Area of doubleRect: " << doubleRect.area() << std::endl;
}

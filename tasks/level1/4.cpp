/*Write a program that contains functions for basic arithmetic operations 
(add, subtract, multiply, divide). Each function should accept two parameters 
and return the result of the operation. Test these functions by invoking them from the main function.*/
#include <iostream>

float division(float a, float b)
{
    return a / b;
}

int add(int a , int b)
{
    return a + b;  
}

int mul(int a , int b)
{
    return a * b;
}

int subtract(int a , int b)
{
    return a - b;
}

int main()
{
    std::cout << "Addition: " <<add(1,2) << std::endl;
    std::cout << "Subtraction: " <<subtract(1,2) << std::endl;
    std::cout << "Multiplication: " <<mul(1,2) << std::endl;
    std::cout << "Division: " << division(1,2) << std::endl; 
}

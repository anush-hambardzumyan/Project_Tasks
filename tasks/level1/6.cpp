/*Create a program that declares an integer variable, 
a pointer variable, and a reference variable. 
Assign the address of the integer to the pointer and manipulate the data
using both the pointer and the reference.*/
#include <iostream>

int main()
{
    int a = 10;
    int* a_ptr = &a;
    int& a_ref = a;

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Address of a: " << a_ptr << std::endl;
    a_ref = 20;
    std::cout << "Value of a after changing: " << a << std::endl;
}
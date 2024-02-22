/*Develop a program that asks the user for a number and then,
using if-else statements, checks whether the number is positive, 
negative, or zero. Extend the program with a switch-case to assign a grade 
(A, B, C, D, F) based on a number range (e.g., 90-100 for A). 
Lastly, implement a loop that prints numbers from 1 to 10. */
#include <iostream>

int main()
{
    int num = 0;
    std::cout << "Enter number:";
    std::cin >> num;
    if(num)
    {
        if(num < 0)
        {
            std::cout << "Number is negative: " << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Number is positive: " << std::endl;
        }
    }
    else
    {
        std::cout << "Number is 0: " << std::endl;
        return 0;
    }

    char grade;

    switch (num)
    {
        case 90 ... 100 :
            grade = 'A';
            break;
        
        case 80 ... 89 :
            grade = 'B';
            break;

        case 70 ... 79 :
            grade = 'C';
            break;

        case 60 ... 69 :
            grade = 'D';
            break;

        case 0 ... 59:
            grade = 'F';
            break;

        default:
            grade = '0';
            break;
    }
    std::cout << "Grade is: "<<grade << std::endl;
}
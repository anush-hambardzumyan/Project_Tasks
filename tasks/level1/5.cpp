/*Implement a program where you define an array of integers and populate it with some values. 
Write functions to find the maximum, minimum, and average values in the array.
Additionally, create a string variable and demonstrate basic string operations like concatenation and length calculation. 
This task focuses on data collection management using arrays and strings.*/
#include <iostream>
#include <string>

int main()
{
    const int size = 5;
    int arr[size];
    std::cout << "Enter the array: " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];
    double sum = 0;
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }

        sum += arr[i];
    }

    std::cout << "Maximal element is: "  << max << std::endl;
    std::cout << "Minimal elemnt is: " << min << std::endl;
    std::cout << "Average element is: " << sum / size << std::endl;
}
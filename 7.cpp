/*Create a program that demonstrates the use of function pointers by
implementing a sorting algorithm selector. This program should allow the user to 
choose between at least two sorting algorithms (e.g., Bubble Sort and Selection Sort) 
to sort an array of integers. The selection of the sorting algorithm will be done through function pointers,
showcasing how they can be used to invoke different functions dynamically based on user input.
*/

#include <iostream>
#include <map>

void sel_sort(int* arr, int size)
{
    std::cout << "Sorted by Selection Sort: " << std::endl;
    for (int i = 0; i < size - 1; ++i) 
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }    
}

void bub_sort(int* arr, int size)
{
    std::cout << "Sorted by Bubble Sort: " << std::endl; 
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main()
{
    int size = 5;
    int arr[size];
    std::cout << "Enter the array: " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    int n = 0;
    std::cout << "Choose the algorithm: 1 - bubble: , 2 - selection:" << std::endl;
    do{std::cin >> n;} while (n != 1 && n!= 2);
    std::map <int , void (*)(int*, int)> mp;
    mp[1] = bub_sort;
    mp[2] = sel_sort;

    mp[n](arr,size);
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}




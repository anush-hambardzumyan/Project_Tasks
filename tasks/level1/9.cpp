#include <iostream>

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

enum SortingStrategy
{ 
    BUBBLE_SORT = 1,
    SELECTION_SORT
};

struct SortingOption
{
    SortingStrategy strategy;
    void (*sort_func)(int*, int);
};

int main()
{
    int size = 5;
    int arr[size];
    std::cout << "Enter the array: " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    int choice;
    std::cout << "Choose the algorithm: 1 - bubble sort, 2 - selection sort: ";
    std::cin >> choice;
    
    SortingOption sortingOptions[] = {
        {BUBBLE_SORT, bub_sort},
        {SELECTION_SORT, sel_sort}
    };

    bool validChoice = false;
    for (const auto& option : sortingOptions) 
    {
        if (static_cast<int>(option.strategy) == choice) 
        {
            validChoice = true;
            option.sort_func(arr, size);
            break;
        }
    }

    if (!validChoice) 
    {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class SortingStrategy 
{
public:
    virtual void sort(std::vector<int>& vec) = 0;
    virtual ~SortingStrategy() = default;
};

class BubbleSort : public SortingStrategy 
{
public:
    void sort(std::vector<int>& arr) override 
    {
        std::cout << "Sorted by Bubble Sort: " << std::endl; 
        for (int i = 0; i < arr.size() - 1; ++i) 
        {
            for (int j = 0; j < arr.size() - i - 1; ++j) 
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
};

class SelectionSort : public SortingStrategy 
{
public:
    void sort(std::vector<int>& arr) override 
    {
        std::cout << "Sorted by Selection Sort: " << std::endl;
        for (int i = 0; i < arr.size() - 1; ++i) 
        {
            int minIndex = i;
            for (int j = i + 1; j < arr.size(); ++j) 
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
};

class FileHandler 
{
public: 
    std::vector<int> readArrayFromFile(const std::string& filename) 
    {
        std::ifstream file(filename);
        std::vector<int> vec;
        if (file.is_open()) 
        {
            std::string str;
            while (std::getline(file, str)) 
            {
                std::istringstream stream(str);
                int num;
                while (stream >> num) 
                {
                    vec.push_back(num);
                }
            }
            file.close();
        } 
        return vec;
    }

    void saveArrayToFile(const std::string& filename, const std::vector<int>& vec) 
    {
        std::ofstream file(filename);
        if (file.is_open()) 
        {
            for (int num : vec) 
            {
                file << num << " ";
            }
            file << std::endl;
            file.close();
        } 
    }
};

class SortingApplication 
{
private:
    SortingStrategy* sortingStrategy;
    FileHandler fileHandler;

public:
    SortingApplication() : sortingStrategy(nullptr) {}

    virtual ~SortingApplication() 
    {
        delete sortingStrategy;
    }

    void selectSortingStrategy() 
    {
        int choice;
        std::cout << "Select sorting algorithm:" << std::endl;
        std::cout << "1. Bubble Sort" << std::endl;
        std::cout << "2. Selection Sort" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        delete sortingStrategy;
        
        switch (choice) 
        {
            case 1:
                sortingStrategy = new BubbleSort();
                break;
            case 2:
                sortingStrategy = new SelectionSort();
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }

    void executeSorting(const std::string& inputFile, const std::string& outputFile) 
    {
        std::vector<int> data = fileHandler.readArrayFromFile(inputFile);
        if (sortingStrategy) 
        {
            sortingStrategy->sort(data);
            fileHandler.saveArrayToFile(outputFile, data);
        } 

        else 
        {
            std::cerr << "Sorting strategy not selected." << std::endl;
        }
    }
};

int main() 
{
    SortingApplication app;
    app.selectSortingStrategy();

    std::string inputFile; 
    std::string outputFile;
    std::cout << "Enter input file name: ";
    std::cin >> inputFile;
    std::cout << "Enter output file name: ";
    std::cin >> outputFile;

    app.executeSorting(inputFile, outputFile);
}

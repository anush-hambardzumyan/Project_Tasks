/*Refactor the sorting algorithm selector to leverage the power of C++ classes, 
encapsulating the sorting algorithms, file operations, and user interactions within a class structure.*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class SortingStrategy
{
    public:
    virtual void sorting(std::vector<int>& vec) = 0;
};

class bub_sort : public SortingStrategy
{
    public:
    void sorting(std::vector<int>& arr)
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

class sel_sort : public SortingStrategy
{
    public:
    void sort(std::vector<int>& arr) 
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
    std::vector<int> splitString(const std::string& input, char delimiter) 
    {
        std::vector<int> parts;
        std::istringstream stream(input);
        std::string part;
        while (std::getline(stream, part, delimiter)) 
        {
            if (!part.empty()) 
            {
                parts.push_back(std::stoi(part));
            }
        }
        return parts;
    }

    std::vector<int> readArrayFromFile(std::ifstream& file)
    {
        file.open("read.txt");
        std::string str;
        std::vector<int> vec;
        while(!file.eof())
        {
            std::getline(file,str);
            vec = splitString(str,' ');
        }
        return vec;
    }

    void saveArrayToFile(std::ifstream& file1,std::ofstream& file2)
    {
        file2.open("write.txt");
        std::vector<int> vec = readArrayFromFile(file1);
        for(int i = 0; i < vec.size(); ++i)
        {
            file2 << vec[i] << " ";
        }
        file2 << '/n';
    }
};

class SortingApplication
{
    private:
        SortingStrategy* ptr;
        FileHandler obj;
};

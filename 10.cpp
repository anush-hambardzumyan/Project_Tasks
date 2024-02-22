/*Write a program that creates a text file and writes a list of names into it. 
Then, open the same file for reading and print its contents to the console.*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
    std::ofstream write;
    std::ifstream read;
    write.open("file.txt");

    std::vector<std::string> fruits;
    fruits.push_back("Apple");
    fruits.push_back("Banana");
    fruits.push_back("Orange");
    fruits.push_back("Grapes");
    fruits.push_back("Mango");

    std::string str;

    for(int i = 0; i < fruits.size(); ++i)
    {
        write << fruits[i] << '\n';
    }

    write.close();

    read.open("file.txt");
    while(!read.eof())
    {
        std::getline(read,str);
        std::cout << str << std::endl;
    }
}
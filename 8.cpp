/*xDefine an enum for days of the week and a struct representing a
Date with day, month, and year as fields. Write a function that prints 
the day of the week and the date in a readable format. */
#include <iostream>
#include <string>

enum Weekdays
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    Date day_x = {18,4,2004};
    int day = Weekdays::Wednesday;
    std::cout << "Year: " << day_x.year << std::endl;
    std::cout << "Month: " << day_x.month << std::endl;
    std::cout << "Day: " << day_x.day << std::endl;
    std::cout << "Weekday: " << day<< std::endl;
}
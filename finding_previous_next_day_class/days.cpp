#include "Days.hpp"
#include<iostream>
using namespace std;

void Day::printing_day()
{
    cout << "Date : " << day << "." << month << "." << year << endl;
}

Day Day::next_day(Day &tomorrow)
{
    int days_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    tomorrow.day = day;
    tomorrow.month = month;
    tomorrow.year = year;

    if(day == days_length[month - 1])
    {
        if(month == 12)
        {
            tomorrow.month = 1;
            tomorrow.year = year + 1;
            tomorrow.day = 1;
        }
        else if(month == 2 && year % 4 == 0)
            tomorrow.day++;
        else
        {
            tomorrow.month++;
            tomorrow.day = 1;
        }
    }
    else
    {
        tomorrow.day++;
    }
    return tomorrow;
}

Day Day::previous_day(Day &yesterday)
{
    int days_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};


    if(day == 1)
    {
        if(month == 1)
        {
            yesterday.day = 31;
            yesterday.month = 12;
            yesterday.year = year - 1;
        }
        else if(month == 3 && year % 4 == 0)
        {
            yesterday.day = 29;
        }
        else
        {
            yesterday.month = month - 1;
            yesterday.day = days_length[yesterday.month - 1];
        }
    }
    else
    {
        yesterday.month = month;
        yesterday.day = day - 1;
        yesterday.year = year;
    }
    return yesterday;
}


#include <iostream>
#include <ctime>
using namespace std;

struct Date
{
    int day,month,year;
};

struct Date age(Date* today, Date* birth);

int main()
{
    Date today,birth,age_user;
    cout << "Welcome to your favorite social media platform\n";
    cout << "Please enter \"day month year\" with spaces : ";
    cin >> birth.day >> birth.month >> birth.year;

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    today.year = now->tm_year + 1900;
    today.month = now->tm_mon + 1;
    today.day = now->tm_mday;

    age_user = age(&today,&birth);
    cout << "You are " << age_user.year << " age years old "<< age_user.day << " months and " << age_user.month << " days" << endl;
    return 0;
}

struct Date age(Date* today, Date* birth)
{
    Date result{};
    if(today->day < birth->day)
    {
        result.day = today->day + 30 - birth->day;
        today->month--;
    }
    else
        result.day = today->day - birth->day;

    if(today->month < birth->month)
    {
        result.month = today->month + 12 - birth->month;
        today->year--;
    }
    else
        result.month = today->month - birth->month;

    result.year = today->year - birth->year;
    return result;
};

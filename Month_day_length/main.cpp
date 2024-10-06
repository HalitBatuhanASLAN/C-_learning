#include <iostream>

using namespace std;

int main()
{
    short int month_num;
    cout << "Enter month number : ";
    cin >> month_num;

    switch(month_num)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "Month has 31 days\n";
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Month has 30 days\n";
            break;
        case 2:
            short int year, day_length;
            cout << "Enter year : ";
            cin >> year;
            day_length = (year % 4 == 0) ? 29 : 28;
            cout << "Month has " << day_length << "days\n";
            break;
        default:
            cout << "Please enter between 1-12";
    }

    return 0;
}

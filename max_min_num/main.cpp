#include <iostream>

using namespace std;

int main()
{
    int number,i = 1,small_num,large_num;
    small_num = INT_MAX;
    large_num = INT_MIN;
    do
    {
        cout << "Enter " << i << "'th number(exit = 0) : ";
        cin >> number;
        if(number == 0) break;
        if(number < small_num) small_num = number;
        if(number > large_num) large_num = number;
        i++;
    }
    while(number != 0);
    if(i != 1)
    {
        cout << "Max number is " << large_num;
        cout << "\nMin number is " << small_num;
    }

    return 0;
}

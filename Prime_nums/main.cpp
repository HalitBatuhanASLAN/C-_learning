#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int number = 1,flag = 1;
    do
    {
        cout << "Enter number (exit : 0) : ";
        cin >> number;
        if(number == 0) break;
        if(number <=1) flag = 0;
        else if(number % 2 == 0 && number != 2) flag = 0;
        else
        {
            flag = 1;
            for(int i = 2;i <= sqrt(number);i++)
            {
                if(number % i == 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0) cout << "Number is not prime\n";
        else cout << "Number is prime\n";
    }
    while(number != 0);
    return 0;
}

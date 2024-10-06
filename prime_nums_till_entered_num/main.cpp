#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    short int number,flag;
    do
    {
        cout << "Enter the max number(exit 0) : ";
        cin >> number;
        if(number == 0) break;
        if(number <= 1) cout << "There is not any prime numbers\n";
        else
        {
            for(int j = 2;j<=number;j++)
            {
                flag = 1;
                for(int i = 2;i<=sqrt(j);i++)
                {
                    if(j % i == 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1) cout << j << " ";
            }
            cout << endl;
        }
    }
    while(number != 0);

    return 0;
}

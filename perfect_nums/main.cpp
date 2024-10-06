#include <iostream>

using namespace std;

int main()
{
    int number,sum{},i,j;
    cout << "Enter max number : ";
    cin >> number;
    for(i = 1; i<=number ; i++)
    {
        sum = 0;
        for(j = 1;j<= i/2;j++)
            sum += (i % j == 0) ? j : 0 ;
        if(sum == i) cout << i << " is a perfect number\n";
    }
    return 0;
}

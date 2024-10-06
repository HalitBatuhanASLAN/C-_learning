#include <iostream>

using namespace std;

int main()
{
    int first,second,third,i,number;
    first = second = third = 1;
    cout << "How many numbers do you want(min 2) : ";
    cin >> number;
    cout << "\n1 1 ";
    for(i = 0;i<number-2;i++)
    {
        first = second;
        second = third;
        third = first + second;
        cout << third << " ";
    }
    cout << endl;
    return 0;
}

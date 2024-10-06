#include <iostream>

using namespace std;

int main()
{
    int number,square_root = 0;
    cout << "Enter a positive number : ";
    cin >> number;

    if(number == 1)
    {
        square_root = 1;
        cout << "The square root of " << number << " is " << square_root << endl;
    }
    else
    {
        for(int i = 1;i<number / 2;i++)
        {
            if(i*i == number)
            {
                square_root = i;
                cout << "The square root of " << number << " is " << square_root << endl;
                break;
            }
        }
    }
    if(square_root == 0) cout << "That number does not have any integer square root\n";
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    /*There can be these kind of usages*/
    int x = 6, y = 5, z;
    z = (x > y) ? x*y : (x == y) ? x%y : y-x;
    cout << z << endl;

    int num,num2,mod;
    cout << "Enter a number : " << endl;
    cin >> num;
    mod = num % 2;
    cout << "Enter another number : " << endl;
    cin >> num2;
    switch(mod)
    {
        case 0:
            cout << "First number is an even num\n";
            break;
        default:
            mod = num2 % 2;
            switch(mod)
            {
                case 0:
                    cout << "Second number is an even num\n";
                    break;
                default:
                    cout << "Both two numbers are not even\n";
            }
    }

    return 0;
}

#include <iostream>

using namespace std;

float exp(float, int);

int main()
{
    float base,result;
    int power;
    cout << "Enter the base : ";
    cin >> base;

    cout << "Enter the power : ";
    cin >> power;

    result = exp(base,power);
    cout << base << " to " << power << " is equal to " << result << endl;
    return 0;
}

float exp(float base, int power)
{
    int result = 1;
    if(base == 0) result = 0;
    else
    {
        if(power == 0) result = 1;
        else if(power < 0)
        {
            for(int i = 1; i <= -power; i++)
                result *= base;
        }
        else
        {
            for(int i = 1; i <= power; i++)
                result *= base;
        }
    }
    return result;
}

#include <iostream>

using namespace std;

int main()
{
    int num1,num2,smallest,EBOB,EKOK;
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number : ";
    cin >> num2;
    smallest = (num1 < num2) ? num1 : num2;
    for(int i = smallest;i >= 1; i--)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            EBOB = i;
            break;
        }
    }
    if(EBOB != 1)
        EKOK = (num1*num2) / EBOB;
    else
        EKOK = num1 * num2;
    cout << "The greatest common divisor is " << EBOB << endl;
    cout << "The least common multiple is " << EKOK << endl;
    return 0;
}

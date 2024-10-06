#include <iostream>

using namespace std;

int factorial(int number);

int main()
{
    int number;
    cout << "Enter number : ";
    cin >> number;
    cout << number << "! = " << factorial(number)<< endl;
    return 0;
}


int factorial(int number) { return (number == 0 || number == 1) ? 1 : number*factorial(number - 1);}

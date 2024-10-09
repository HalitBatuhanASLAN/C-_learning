#include <iostream>

using namespace std;

int sum(int num1,int num2);
int multiply(int num1,int num2);

int main()
{
    int (*func)(int,int);

    int num1 = 5, num2 = 12;
    func = sum;
    cout << "num1 + num2 = " << func(num1,num2) << endl;
    func = &multiply;
    cout << "num1 * num2 = " << func(num1,num2) << endl;

    return 0;
}

int sum(int num1,int num2)
{
    return num1 + num2;
}

int multiply(int num1,int num2)
{
    return num1 * num2;
}

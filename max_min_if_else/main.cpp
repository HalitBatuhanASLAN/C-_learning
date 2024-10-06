#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3, max_num, min_num;
    cout << "Enter 3 numbers;\n";
    cin >> num1 >> num2 >> num3;

    if((num1 > num2) && (num1 > num3))
    {
        max_num = num1;
        min_num = (num2 < num3) ? num2 : num3;
    }
    else if((num2 > num1) && (num2 > num3))
    {
        max_num = num2;
        min_num = (num1 < num3) ? num1 : num3;
    }
    else
    {
        max_num = num3;
        min_num = (num1 < num2) ? num1 : num2;
    }

    cout << "Max num is " << max_num;
    cout << "\nMin num is " << min_num;
    return 0;
}

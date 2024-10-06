#include <iostream>

using namespace std;

int main()
{
    int num1 = 7, num2 = 3, result;
    /*
    * 7 = 0000 0111
    * 3 = 0000 0011
    */
    result = num1 & num2;//and
    cout << "num1 & num2 = " << result << endl;

    result = num1 | num2;//or
    cout << "num1 | num2 = " << result << endl;

    result = num1 ^ num2;//xor-if same result 0 else 1
    cout << "num1 ^ num2 = " << result << endl;

    result = num1 >> num2;//rigth shift
    cout << "num1 >> num2 = " << result << endl;

    result = num1 << num2;//left shift
    cout << "num1 << num2 = " << result << endl;

    return 0;
}

#include <iostream>
#include <cassert>
//#define DEBUG
using namespace std;

float division(int dividend,int divider);

int main()
{
    int dividend = 15,divider = 0;
    float result;
    result = division(dividend,divider);
    cout << "Result is " << result << endl;
    return 0;
}
float division(int dividend,int divider)
{
    #ifndef DEBUG
        assert(divider != 0 && "divider can not be 0");
        cout << endl;
    #endif // DEBUG
    float result = static_cast<float>(dividend) / divider;
    return result;
}

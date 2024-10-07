#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int divider,dividend;
    float result;
    cout << "Enter dividend : ";
    cin >> dividend;
    cout << "Enter divider : ";
    cin >> divider;

    assert(divider != 0 && "divider can not be 0");
    result = static_cast<float>(dividend) / divider;
    cout << "Result is " << result << endl;
    return 0;
}

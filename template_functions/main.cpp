#include <iostream>

using namespace std;

template<typename T>
void swap_values(T& val1,T& val2)
{
    T tmp = val1;
    val1 = val2;
    val2 = tmp;
}

template<class T>//we can write both class and typename
T sum(T& num1,T& num2)
{
    return num1 + num2;
}

int main()
{
    int a = 5, b = 9;
    cout << a << "\t" << b << endl;
    swap_values(a,b);
    cout << a << "\t" << b << endl;

    cout << "--------------\n";

    char x = 'F', y = 'B';
    cout << x << "\t" << y << endl;
    swap_values<char>(x,y);//it is not needed but we can write it too
    cout << x << "\t" << y << endl;



    return 0;
}

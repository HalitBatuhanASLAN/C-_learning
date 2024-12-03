#include <iostream>

using namespace std;

template<typename T>
class A
{
    public:
        A(T variable):variable(variable){}
        T variable;
};

int main()
{
    /*for sending variable to classes we must use type of variable*/
    A<int> obj1(15);
    A<double> obj2(1907.1907);
    A<char> obj3('A');

    cout << "Object 1 is : " << obj1.variable << endl;
    cout << "Object 2 is : " << obj2.variable << endl;
    cout << "Object 3 is : " << obj3.variable << endl;
    return 0;
}

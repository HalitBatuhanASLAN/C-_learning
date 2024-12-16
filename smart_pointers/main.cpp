#include <iostream>
#include<memory>
using namespace std;

int main()
{
    unique_ptr<int> u_ptr = make_unique<int>(12);
    cout << *u_ptr << endl;

    unique_ptr<int> ptr2 = move(u_ptr);
    cout << *ptr2 << endl;

    return 0;
}

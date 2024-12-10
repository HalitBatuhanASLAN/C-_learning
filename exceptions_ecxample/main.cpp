#include <iostream>
#include<stdexcept>
using namespace std;

void error_func()
{
    try
    {
        throw bad_alloc();
    }
    catch(...)
    {
        cout << "Problem found in function\n";
        throw;//throw the last error
        //we can throw another error too
        throw overflow_error("Overflow error\n");
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    try
    {
        int index;
        cout << "Enter index number :";
        cin >> index;
        if(index < 0 || index > 9)
            throw out_of_range("Index must be between 0-9");
        else
            cout << arr[index] << endl;
    }
    catch(exception& e)
    {
        cout << "Problem occured " << e.what();
    }

    cout << endl;

    try
    {
        error_func();
    }
    catch(exception& e)
    {
        cout << "Problem in main function " << e.what();
    }

    return 0;
}

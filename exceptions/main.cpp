#include <iostream>

using namespace std;

int main()
{
    try
    {
        string name;
        cout << "Enter your name :";
        cin >> name;
        if(name.length() <= 1)
            throw -1;
        else
            cout << "Welcome " << name << endl;
    }
    catch(int err)//we can delete this part like following
    {
        cout << "Name must contain more than 1 letter\n";
        cout << "Error code :" << err << endl;
    }
    /*
    catch(...)
    {
        cout << "Name must contain more than 1 letter\n";
        //cout << "Error code :" << err << endl;
    }*/
    return 0;
}

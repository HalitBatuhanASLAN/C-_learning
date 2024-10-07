#include <iostream>
#include <string>

using namespace std;

int main()
{
    string txt1,txt2,largest;
    txt1 = "Halit";
    txt2 = "Batuhan";
    largest = (txt1 > txt2) ? txt1 : txt2;
    cout << "Largest string is " << largest << endl;

    string empty_string{};
    if(!empty_string.empty())
        cout << "String is not empty" << endl;
    else
        cout << "String is empty" << endl;
    return 0 ;
}

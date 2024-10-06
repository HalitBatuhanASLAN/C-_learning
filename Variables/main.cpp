#include <iostream>
#include <string>
#include <clocale>//to use Turkish characters

using namespace std;

int main()
{
    /*Do not assign integer values to boolean*/
    /*When you delete something from a social media
    platform or another place it does not deleted.
    They just add new column to their database and
    assign false value to there.
    */
    bool is_true = true;

    /*Variables names can start with only letters and underscore(_)*/
    /*C++ has case sensitivity*/
    string my_name = "Halit Batuhan ASLAN";
    cout << "My name is " << my_name << endl;

    int my_age;
    my_age = 20;
    cout << "My age is " << my_age << endl;

    /*in constants we must initialize value at the same line*/
    const float PI = 3.14f;//we put "f" end of value for float variables
    cout << "Value of PI number is " << PI << endl;

    /*static type casting*/
    double ph = 7.14;
    ph = static_cast<int>(ph);
    cout << "Ph value is " << ph << endl;

    /*unsigned variables are positive*/
    unsigned pos_num = 15;//if we assign negative num than it will print
    //something like garbege value

    double var_double = 12E5;//12*10^5
    cout << "Variable of double " << var_double << endl;

    /*to use Turkish characters*/
    setlocale(LC_ALL,"Turkish");
    cout << "эрью" << endl;
    return 0;
}

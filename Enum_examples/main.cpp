#include <iostream>

using namespace std;

enum class Months
{
    January = 1,February,March,April,May,June,July,
    August,September,October,November,December
};
//by using enum class(strong enum) it makes more safer and it allows as
//same names with enum things and we should scope resolution operator

struct Year
{
    //public:
        Months m;
};

int main()
{
    Months m1 = Months::January;
    for(int i = 1;i<=(int)Months::December;i++)
        cout << i << endl;

    Year y;
    y.m = June;//for that one we should delete class in enum
    cout << y.m << endl;
    return 0;
}

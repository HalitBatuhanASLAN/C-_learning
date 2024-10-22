#include<iostream>

using namespace std;

class MathUtils
{
    public:
        static double circle_area(int radius)
        {
            return(PI*radius*radius);
        }
    private:
        static const double PI;
};

const double MathUtils::PI = 3.14159;

int main()
{
    MathUtils circle1;
    cout << "Area of circle is " << circle1.circle_area(15) << endl;

    return 0;
}
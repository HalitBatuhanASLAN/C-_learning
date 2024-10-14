#include <iostream>
#include <string>

using namespace std;

class Car
{
    public://access specifier
        int year;//attribute(proporty)
        string name;
        string color;

        //even we dont write contructrs like following it created by automaticly
        Car()
        {
            cout << "Your car object is created.\n";
        }

        Car(int y, string n, string c)
        {
            year = y;
            name = n;
            color = c;
        }

        void age()//method
        {
            cout << "Your car is " << 2024 - year << " years old.\n";
        }
        int max_speed(unsigned int);
};

int Car::max_speed(unsigned int speed)
{
    return speed;
}

int main()
{
    Car ford;//object created

    ford.color = "Blue";
    ford.name = "Mondeo";
    ford.year = 2016;
    ford.age();
    cout << "Maximum speed of your car is " << ford.max_speed(253) << endl;

    Car mercedes(1997,"E series","red");


    return 0;
}

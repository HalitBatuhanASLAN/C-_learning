#include"Person.h"
#include<iostream>
using namespace std;

namespace School
{
    void Person::introduce()
    {
        cout << "My name is " << name << endl;
    }
}
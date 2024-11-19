#include"Student.h"
#include<iostream>
using namespace std;

namespace School
{
    void Student::study()
    {
        cout << "I am at " << grade << "'th class\n";
    }
}
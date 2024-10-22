#include <iostream>

using namespace std;

class Students
{
    public:
        Students(){num_of_students++;}
        static int num_of_students;
        static void printing_students(string name, int age);
};

int Students::num_of_students = 0;

void Students::printing_students(string name, int age)
{
    cout << name << " is one of student in " << Students::num_of_students;
    cout << ".And his/her age is " << age << endl;
}

int main()
{
    Students hba,s[2];
    Students::printing_students("Halit Batuhan ASLAN",20);

    return 0;
}

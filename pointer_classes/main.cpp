#include <iostream>
#include<string>
using namespace std;

class Student
{
    public:
        Student();
        Student(int cla,string n):std_class(cla),name(n){};

        void setClass(int in_class){std_class = in_class;};
        void setName(string n){name = n;};

        int getClass(){return std_class;};
        string getName(){return name;};
    private:
        int std_class;
        string name;
};

void print_attributes(Student *s)
{
    cout << s->getClass() << " and name is " << s->getName() << endl;
}

int main()
{

    Student s1(12,"HBA");

    print_attributes(&s1);

    Student* s2 = &s1;
    s2->setClass(10);
    print_attributes(s2);
    print_attributes(&s1);

    return 0;
}

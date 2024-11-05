#include <iostream>
#include<string>
using namespace std;

class Student
{
    public:
        void setName(string n){name = n;}
        void setAge(int a){*age = a;}

        string getName(){return name;}
        int getAge(){return *age;}
        ~Student(){delete age;}
    private:
        int* age = new int;
        string name;
};

int main()
{
    Student* s1= new Student;
    s1->setAge(20);
    s1->setName("HBA");

    cout << s1->getAge() << "   " << s1->getName() << endl;
    delete s1;
    return 0;
}

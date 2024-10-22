#include<iostream>
#include<string>
using namespace std;

class Person
{
    public:
        Person(string in_name,int in_age): name(in_name), age(in_age){}
        Person(string in_name) : name(in_name), age(18){}
        Person(): name("Unknown"), age(18), adress("N/A"){}
        
        string getName(){return name;}
        string getAddress(){return adress;}
        int getAge(){return age;}
    
        void setName(string in_name){name = in_name;}
        void setting_adress(string in_adress){adress = in_adress;}
        void setAge(int in_age){age = in_age;}

    private:
        string name;
        int age;
        string adress;
};

class Employee
{
    public:
        Employee(string in_name,int in_age,int in_salary = 0): p(in_name,in_age) , salary(in_salary){}
        void print();
        void setSalary(int in_salary){salary = in_salary;}
        int getSalary(){return salary;}
        Person& getPerson(){return p;}
    private:
        int salary;
        Person p;
};

void Employee::print()
{
    cout << "Name is " << getPerson().getName() << " and age is " << getPerson().getAge() << endl;
    cout << "Salary of person is " << getSalary() << endl;
    cout << "His/Her adress is " << getPerson().getAddress() << endl;
}



int main() {
    // Test Drive Code

    // Create a Person object using the default constructor
    Person person1;
    cout << "Person 1: Name: " << person1.getName() << ", Age: " << person1.getAge() << ", Address: " << person1.getAddress() << endl;

    // Create a Person object using the constructor with name
    Person person2("Alice");
    cout << "Person 2: Name: " << person2.getName() << ", Age: " << person2.getAge() << ", Address: " << person2.getAddress() << endl;

    // Create a Person object using the constructor with name and age
    Person person3("Bob", 30);
    cout << "Person 3: Name: " << person3.getName() << ", Age: " << person3.getAge() << ", Address: " << person3.getAddress() << endl;
    person3.setting_adress("araba");
    cout << "Person 3: Name: " << person3.getName() << ", Age: " << person3.getAge() << ", Address: " << person3.getAddress() << endl;

    // Create an Employee object
    Employee emp1("Charlie", 25, 5000);
    cout << "\nEmployee Details:" << endl;
    emp1.print();  // Print employee details

    // Modify the employee's details
    emp1.setSalary(6000);
    emp1.getPerson().setName("araba");

    cout << "\nUpdated Employee Details:" << endl;
    emp1.print();  // Print updated employee details

    return 0;
}
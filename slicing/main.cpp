#include <iostream>
using namespace std;

class Base
{
    public:
        Base()=default;
        virtual void show(){cout << "Base class show\n";}
        virtual void display(){cout << "Base class display\n";}
};

class Derived:public Base
{
    public:
        void show() override {cout << "Derived class show\n";}
        void display() override {cout << "Derived class display\n";}
        void derivedMethod(){cout << "Derived class special metod\n";}
};

int main() {
    // Create a Derived class object
    Derived derivedObj;

    // 1. Demonstrating Object Slicing through Assignment
    cout << "Object slicing during assignment:" << endl;
    Base baseObj = derivedObj;  // Object slicing happens here

    // 2. Using the Base object after slicing
    baseObj.show();  // Will call Base's version of show() due to slicing
    baseObj.display();  // Calls Base class display()

    // 3. Attempting to call Derived-specific method will fail after slicing
    // baseObj.derivedMethod(); // Uncommenting this will cause a compilation error.

    // 4. Using pointers to avoid slicing
    cout << "\nUsing pointers to avoid slicing:" << endl;
    Base* basePtr = &derivedObj;  // No slicing here, we are using polymorphism
    basePtr->show();  // Will call Derived's version of show()
    basePtr->display();  // Will call Base's display()
    derivedObj.derivedMethod();

    return 0;
}
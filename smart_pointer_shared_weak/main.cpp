#include <iostream>
#include<memory>

using namespace std;

class Student
{
    public:
        int age;
        int school_num;
};
int main()
{
    shared_ptr<Student> ptr1 = make_shared<Student>();
    ptr1->age = 12;
    ptr1->school_num = 123456789;

    cout << "Age : " << ptr1->age << " Std_num : " << ptr1->school_num << endl;

    cout << ptr1.use_count() << endl;//give us the pointer amount which points the current object
                                    //gives 2

    shared_ptr<Student> ptr2 =ptr1;
    cout << ptr1.use_count() << endl;//gives 2

    shared_ptr<int> num_ptr = make_shared<int>(12);
    weak_ptr<int> w_ptr = num_ptr;
    cout << *w_ptr.lock() << endl;//to access we use lock
    if(*w_ptr.expired())
        cout << *w_ptr.lock() << endl;
    else
        cout << "object deleted\n";
    num_ptr.reset();//deletes pointer
    return 0;

}

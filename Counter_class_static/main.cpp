#include<iostream>
#include<string>

using namespace std;

class Counter
{
    public:
        Counter(){count++;}
        static int getCount() { return count;} 
        void setValue(int in_value);
        int getValue() { return value;}
    private:
        int value;
        static int count;
};

int Counter::count = 0;

void Counter::setValue(int in_value)
{
    if(in_value > 0)
        value = in_value;
    else
        cerr << "It is not illegel enter positive value!!\n";
}


int main() {
    // Test Code
    cout << "Initial count of Counter objects: " << Counter::getCount() << endl;

    // Create first Counter object
    Counter counter1;
    cout << "Count after creating counter1: " << Counter::getCount() << endl;

    // Set a value for counter1
    counter1.setValue(10);
    cout << "Counter1 value: " << counter1.getValue() << endl;

    // Attempt to set an invalid value for counter1
    counter1.setValue(-5);  // Should trigger an error message

    // Create second Counter object
    Counter counter2;
    cout << "Count after creating counter2: " << Counter::getCount() << endl;

    // Set a value for counter2
    counter2.setValue(20);
    cout << "Counter2 value: " << counter2.getValue() << endl;

    // Create third Counter object
    Counter counter3;
    cout << "Count after creating counter3: " << Counter::getCount() << endl;

    // Set a value for counter3
    counter3.setValue(30);
    cout << "Counter3 value: " << counter3.getValue() << endl;

    // Display values and count for all Counter instances
    cout << "\nFinal values and count:" << endl;
    cout << "Counter1 value: " << counter1.getValue() << endl;
    cout << "Counter2 value: " << counter2.getValue() << endl;
    cout << "Counter3 value: " << counter3.getValue() << endl;
    cout << "Total Counter objects created: " << Counter::getCount() << endl;

    return 0;
}
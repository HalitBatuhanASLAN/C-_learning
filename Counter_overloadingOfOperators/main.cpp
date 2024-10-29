#include <iostream>
using namespace std;

class Counter
{
    public:
        Counter();
        Counter(int in_value);

        int getValue();
        void setValue(int in_value);

        friend istream& operator>>(istream& in,Counter &c); 
        friend ostream& operator<<(ostream& out,Counter& c);

        Counter operator++();
        Counter operator++(int ignore);
    private:
        int value;
};

Counter::Counter():value(0){}
Counter::Counter(int in_value):value(in_value){}

int Counter::getValue(){return value;}
void Counter::setValue(int in_value){value = in_value;}

istream& operator>>(istream& in,Counter &c)
{
    int input;
    in >> input;
    c.setValue(input);
    return in;
}
ostream& operator<<(ostream& out,Counter& c)
{
    out << c.getValue();
    return out;
}
//pre inc
Counter Counter::operator++()
{
    setValue(getValue() + 1);
    return Counter(getValue()); 
}
//post inc
Counter Counter::operator++(int ignore)
{
    Counter my_initial(getValue());
    setValue(getValue() + 1);
    return my_initial;
}

int main() {
    Counter c1;
    Counter c2(10);   

    cout << "Initial value of c1: " << c1.getValue() << endl;
    c1.setValue(5);
    cout << "Updated value of c1: " << c1 << endl;

    cout << "Enter a new value for c1: ";
    cin >> c1;
    cout << "New value of c1: " << c1 << endl;

    cout << "c2: " << c2 << endl;
    ++c2;
    cout << "++c2: " << c2 << endl;    
    
    cout << "c2++: " << c2 << endl;
    c2++;
    cout << "After c2++: " << c2 << endl;

    return 0;
}

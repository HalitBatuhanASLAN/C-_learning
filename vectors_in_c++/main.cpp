#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;//it allocates automaticly
    if(numbers.empty())
        cout << "vector is empty\n";

    for(int i = 1;i<10;i++)
        numbers.push_back(i);//adding and of vector

    for(int i : numbers)
        cout << numbers.at(i-1) << " ";//same with numbers[i]
    cout << endl;
    cout << numbers.size() << endl;

    cout << numbers.back() << endl;
    cout << numbers.front() << endl;
    numbers.erase(numbers.begin() + 5);
    //cout << numbers.back() << endl;

    for(int i = 0;i<numbers.size();i++)
        cout << numbers[i];
    cout << endl;
    numbers.resize(15);
    cout << numbers.size() << endl;

    return 0;
}

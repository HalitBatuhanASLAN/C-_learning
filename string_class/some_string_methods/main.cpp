#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    cout << "Enter a sentence : ";
    getline(cin,sentence);

    cout << sentence << endl;
    cout << sentence.size() << endl;//it prints size
    cout << sentence.length() << endl;//it prints length
    cout << sentence.capacity() << endl;//it prints allocated capacity for that string
    cout << sentence.max_size() << endl;//max size of string

    sentence.resize(30,'+');//increase size and adds character end of the string
    cout << sentence << endl;
    sentence.resize(10);//just gives 10 characters capacity
    cout << sentence << endl;

    cout << "third character is " << sentence.at(2) << endl;
    cout << "first character is " << sentence.front() << endl;
    cout << "last character is " << sentence.back() << endl;

    sentence.front() = '1';//changes first character
    sentence.back() = '1';//changes last character
    cout << "first character is " << sentence.front() << endl;
    cout << "last character is " << sentence.back() << endl;

    sentence.shrink_to_fit();//it changes allocated capacity to make it contains less capacity

    sentence.clear();//clears string
    cout << sentence << endl;
    return 0;
}

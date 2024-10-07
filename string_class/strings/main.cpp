#include <iostream>
#include <string>

using namespace std;

int main()
{
    string full_name;
    cout << "Enter your full name : ";
    getline(cin,full_name);
    cout << "Your name is " << full_name
    << " and first character is " << full_name[0]
    << " and total size is " << full_name.size() << endl;//and also full_name.length()

    string example;
    example = "Hello " + full_name;
    example.append(3,'.');
    cout << example << endl;

    string txt(5,'A');
    cout << txt << endl;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
const string PASWORD = "hello_c++";
int main()
{
    string sentence,word_one,word_two;
    sentence = "Hello programer. It is good to see you:)";
    cout << sentence << endl;
    word_one = sentence.substr(5,5);//it takes 5 character from fifth index character
    cout << word_one << endl;
    int index = sentence.find("It");
    word_two = sentence.substr(index);
    cout << word_two << endl;

    string pasword{};
    cout << "Enter your password : ";
    getline(cin,pasword);
    if(PASWORD.compare(pasword) == 0)
        cout << "Welcome programmer\n";
    else
        cout << "Wrong password. Try again\n";
    return 0;
}

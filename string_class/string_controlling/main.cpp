#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string sentence;
    cout << "Enter a sentence : ";
    getline(cin,sentence);
    for(char character : sentence)
    {
        if(isalpha(character))
            cout << character << " is a letter\n";
        else if(isdigit(character))
            cout << character << " is a number\n";
        else
            cout << character << " is neither letter nor number\n";
    }
    return 0;
}

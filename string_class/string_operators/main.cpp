#include <iostream>
#include <string>

using namespace std;

int main()
{
    string txt,txt2,txt3;
    txt2 = "Hello c++";
    txt3 = "I'm a programmer";
    cout << "Txt2 = " << txt2 << endl;
    cout << "Txt3 = " << txt3 << endl;
    txt.append(txt2,2,1);
    cout << "txt = " << txt << endl;

    txt2.insert(5,txt3);//add inside txt2 from fifth character
    cout << "txt2 = " << txt2 << endl;
    txt.assign(txt2);//assigns from beginning to end
    cout << "txt = " << txt << endl;

    string seller = "car";
    string buyer = "money";
    seller.swap(buyer);
    cout << "Seller has " << seller << endl;
    cout << "Buyer has " << buyer << endl;


    string example = "Hello C++.";
    cout << example << endl;
    example.pop_back();//deletes last character
    cout << example << endl;


    string exa_erase = "This is an example sentence to show erase method";
    exa_erase.erase(10,8);//deletes 8 characters from tenth character
    cout << exa_erase << endl;

    string exa_replace = "This is a sentence to show some usages of replace";
    exa_replace.replace(5,2,"ABCDEF");//from 5th character delete 2 characters and replace them with "ABCDEF"
    cout << exa_replace << endl;

    return 0;
}

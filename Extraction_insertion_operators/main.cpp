#include <iostream>
#define PI 3.14

using namespace std;

int main()
{
    /*
    * << insertion operator
    * >> extraction operator
    */
    string name;
    cout << "Enter your name : ";
    getline(cin,name);//it reads all line
    cout << name << endl;

    double radius,area,circumference;
    cout << "Enter the radius of circle : ";
    cin >> radius; //
    area = PI * radius * radius;
    circumference = 2 * PI * radius;
    cout << "Area of circle : " << area << endl;
    cout << "Circumference of circle : " << circumference << endl;

    /*we should use these kind of character taking without any cin before that line*/
    /*char text[100];
    cout << "Enter a message : ";
    cin.getline(text,sizeof(text));
    cout << text << endl;*/

    return 0;
}

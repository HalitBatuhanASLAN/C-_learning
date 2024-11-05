#include <iostream>
#include<string>
using namespace std;

int main()
{
    /*
    int* num = new int;
    *num = 5;
    cout << *num << endl;
    delete num;

    int* x = nullptr;
    x = new int;
    *x = 15;
    */

    int num_of_cars{};
    cout << "How many cars do you have : ";
    cin >> num_of_cars;

    double* car_engines = new double[num_of_cars];
    cout << "Enter car motors\n";

    for(int i = 0;i<num_of_cars;i++)
        cin >> car_engines[i];

    for(int i = 0;i<num_of_cars;i++)
        cout << car_engines[i] << endl;

    cout << endl << endl;

    string* brands = new string[num_of_cars];
    cout << "Enter cars' brands;\n";

    for(int i = 0; i<num_of_cars;i++)
        cin >> *(brands + i);

    for(int i = 0;i<num_of_cars;i++)
        cout << *(brands + i) << endl;

    delete[] car_engines;
    delete[] brands;
    return 0;
}

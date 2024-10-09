#include <iostream>

using namespace std;

int main()
{
    int arr_size{};
    cout << "Enter size of array : ";
    cin >> arr_size;

    int *my_arr = new int[arr_size];
    for(int i = 0;i<arr_size;i++)
    {
        cout << "Enter " << i + 1 << "th element : ";
        cin >> my_arr[i];
    }

    for(int i = 0; i<arr_size; i++)
        cout << *(my_arr + i) << " ";

    delete[] my_arr;
    my_arr = NULL;
    return 0;
}

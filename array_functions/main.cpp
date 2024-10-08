#include <iostream>
#include <climits>
#define CAPACITY 10
using namespace std;

void fill_array(int *arr,int capacity);
void printing_array(const int *arr,int capacity);
void find_even_odd(const int *arr,int capacity);
void reverse_array(int *arr, int capacity);
void sorting(int *arr,int capacity);
int min_num_index(int *arr,int capacity);
int max_num_index(int *arr,int capacity);

int main()
{
    int arr[CAPACITY]{};
    int capacity = CAPACITY;

    cout << "Before filling\n";
    printing_array(arr,capacity);

    fill_array(arr,capacity);
    cout << "After filling\n";
    printing_array(arr,capacity);

    cout << endl;
    find_even_odd(arr,capacity);

    reverse_array(arr,capacity);
    cout << "After reversing\n";
    printing_array(arr,capacity);

    int min_num = arr[min_num_index(arr,capacity)];
    int max_num = arr[max_num_index(arr,capacity)];
    cout << "Max num is " << max_num << endl;
    cout << "Min num is " << min_num << endl;

    sorting(arr,capacity);
    cout << "After sorting\n";
    printing_array(arr,capacity);


    return 0;
}

void fill_array(int *arr,int capacity)
{
    int number;
    for(int i = 0;i<capacity;i++)
    {
        cout << "Enter the " << i + 1 << " element : ";
        cin >> number;
        arr[i] = number;
    }
}

void printing_array(const int *arr,int capacity)
{
    for(int i = 0;i<capacity;i++)
        cout << arr[i] << " ";
    cout << endl;
}

void find_even_odd(const int *arr,int capacity)
{
    for(int i = 0;i<capacity;i++)
    {
        if(arr[i] % 2 == 0)
            cout << arr[i] << " is even\n";
        else
            cout << arr[i] << " is odd\n";
    }
}

void reverse_array(int *arr, int capacity)
{
    int tmp;
    for(int i = 0;i<capacity;i++,capacity--)
    {
        tmp = arr[i];
        arr[i] = arr[capacity-1];
        arr[capacity-1] = tmp;
    }
}

void sorting(int *arr,int capacity)
{
    int tmp;
    for(int i = 0;i<capacity - 1;i++)
    {
        for(int j = 0; j < capacity - i - 1;j++)
        {
            if(arr[j] > arr[j +1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int min_num_index(int *arr,int capacity)
{
    int min_num = INT_MAX;
    int min_index = 0;
    for(int i = 0;i<capacity;i++)
    {
        if(min_num > arr[i])
        {
            min_index = i;
            min_num = arr[i];
        }
    }
    return min_index;
}
int max_num_index(int *arr,int capacity)
{
    int max_num = INT_MIN;
    int max_index = 0;
    for(int i = 0;i<capacity;i++)
    {
        if(max_num < arr[i])
        {
            max_index = i;
            max_num = arr[i];
        }
    }
    return max_index;
}


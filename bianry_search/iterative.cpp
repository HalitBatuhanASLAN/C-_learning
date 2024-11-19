#include<iostream>
using namespace std;

bool binary_search(int elements[],int size, int target);

int main()
{
    int array[8] = {1,5,6,7,9,12,42,55};
    int size = 8;
    bool is_find = binary_search(array,size,42);
    if(is_find)
        cout << "Target found\n";
    else
        cout << "Target did not find\n";
    return 0;

}

bool binary_search(int elements[],int size, int target)
{
    int num = elements[size/2];
    int middle_index = size/2;
    int starting = 0,last = size-1;
    while(starting <= last)
    {
        if(num == target)
            return true;
        else if(num < target)
        {
            starting = middle_index+1;
            middle_index = (starting + last) / 2; 
        }
        else
        {
            last = middle_index-1;
            middle_index = (starting + last) / 2;
        }
        num = elements[middle_index];
    }
    return false;
}
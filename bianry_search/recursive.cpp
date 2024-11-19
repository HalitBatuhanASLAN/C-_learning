#include<iostream>
using namespace std;

bool binary_search(int elements[],int starting,int end, int target);

int main()
{
    int array[8] = {1,5,6,7,9,12,42,55};
    int size = 8;
    bool is_find = binary_search(array,0,size-1,1);
    if(is_find)
        cout << "Target found\n";
    else
        cout << "Target did not find\n";
    return 0;

}

bool binary_search(int elements[],int starting,int end, int target)
{
    int middle = (end+starting)/2;
    int num = elements[middle];
    if(target == num)
        return true;
    else if(starting > end)
        return false;
    else if(num < target)
    {
        starting = middle+1;
        return(binary_search(elements,starting,end,target));
    }
    else if(num > target)
    {
        end = middle-1;
        return(binary_search(elements,starting,end,target));
    }
}
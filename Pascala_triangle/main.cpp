#include <iostream>

using namespace std;

int main()
{
    int current_row,current_column,max_row,max_column,number,gap;
    cout << "Enter the row number : ";
    cin >> max_row;
    for(current_row = 0;current_row < max_row;current_row++)
    {
        for(gap = 0; gap < max_row - current_row;gap++)
            cout << "  ";
        for(current_column = 0;current_column <= current_row;current_column++)
        {
            if(current_column == 0) number = 1;
            else number = (number * (current_row - current_column + 1)) / current_column;
            cout << number << "  ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int size_of_matrix;
    cout << "Enter the size of matrix(must be odd number) : ";
    cin >> size_of_matrix;
    bool matrix[size_of_matrix][size_of_matrix]{};

    for(int i = 0;i<size_of_matrix;i++)
    {
        matrix[i][i] = 1;
        matrix[i][size_of_matrix-i-1] = 1;
    }

    for(int i = 0;i<size_of_matrix;i++)
    {
        for(int j = 0;j < size_of_matrix;j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int row_of_matrix,column_of_matrix,number;
    cout << "Enter the row number of matrix : ";
    cin >> row_of_matrix;
    cout << "Enter the column number of matrix : ";
    cin >> column_of_matrix;

    int matrix_1[row_of_matrix][column_of_matrix]{};
    int matrix_2[row_of_matrix][column_of_matrix]{};
    int result_matrix[row_of_matrix][column_of_matrix]{};

    cout << "For first matrix;\n";
    for(int i = 0;i<row_of_matrix;i++)
    {
        for(int j = 0;j<column_of_matrix;j++)
        {
            cout <<  "Enter " << i+1 << "th row " << j+1 << "th column value : ";
            cin >> number;
            matrix_1[i][j] = number;
        }
    }

    for(int i = 0;i<row_of_matrix;i++)
    {
        for(int j = 0;j<column_of_matrix;j++)
            cout << matrix_1[i][j] << " ";
        cout << endl;
    }

    cout << "For second matrix;\n";
    for(int i = 0;i<row_of_matrix;i++)
    {
        for(int j = 0;j<column_of_matrix;j++)
        {
            cout <<  "Enter " << i+1 << "th row " << j+1 << "th column value : ";
            cin >> number;
            matrix_2[i][j] = number;
        }
    }
    for(int i = 0;i<row_of_matrix;i++)
    {
        for(int j = 0;j<column_of_matrix;j++)
            cout << matrix_2[i][j] << " ";
        cout << endl;
    }

    int sum = 0;
    for(int i = 0;i< row_of_matrix;i++)
    {
        for(int j = 0;j<column_of_matrix;j++)
        {
            sum = 0;
            for(int k = 0;k<row_of_matrix;k++)
                sum  += matrix_1[i][k]*matrix_2[k][j];
            result_matrix[i][j] = sum;
        }
    }

    cout << "The multiply of those two matrix is;\n";
    for(int i = 0;i<row_of_matrix;i++)
    {
        for(int j = 0;j<column_of_matrix;j++)
            cout << result_matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}

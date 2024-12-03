#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
    public:
        Matrix<T>(int row, int column):row(row),column(column)
        {
            t = new T*[row];
            for(int i = 0;i<row;i++)
            {
                t[i] = new T(column);
            }
        }
        void set(int row,int column, T value){t[row][column] = value;}
        T get(int row,int column){return t[row][column];}
        void print()
        {
            for(int i = 0;i<row;i++)
                for(int j = 0;j<column;j++)
                    cout << get(i,j) << " ";
                cout << endl;
        }
        ~Matrix()
        {
            for(int i = 0;i<row;i++)
                delete[] t[i];
            delete[] t;
        }
    private:
        T** t;
        int row,column;
};

int main()
{
    // Create a 2x2 matrix of integers
    Matrix<int> m1(2, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);
    cout << "Matrix m1 (2x2):" << endl;
    m1.print();  // Print the 2x2 matrix

    // Create a 3x3 matrix of doubles
    Matrix<double> m2(3, 3);
    m2.set(0, 0, 1.1);
    m2.set(1, 1, 2.2);
    m2.set(2, 2, 3.3);
    cout << "Matrix m2 (3x3):" << endl;
    m2.print();  // Print the 3x3 matrix

    // Accessing elements directly
    cout << "Accessing m1[0][1]: " << m1.get(0, 1) << endl;  // Should output 2

    return 0;
}
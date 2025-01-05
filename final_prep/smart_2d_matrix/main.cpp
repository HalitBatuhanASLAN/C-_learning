#include <iostream>
using namespace std;
#include <memory> // For std::unique_ptr

template<typename T>
class Matrix
{
    public:
        Matrix(const int& ro,const int& col):row(ro),column(col)
        {
            data = make_unique<unique_ptr<T[]>[]>(row);
            for(int i = 0;i<row;i++)
            {
                data[i] = make_unique<T[]>(column);
                /*for(int j = 0;j<column;j++)
                    data[i][j] = 0;*/
            }
        }

        void setElement(const int& line,const int& col,const T& value)
        {
            data[line][col] = value;
        }
        T getData(const int& li,const int& ro)const{return data[li][ro];}

        void print()const
        {
            for(int i = 0;i<row;i++)
            {
                for(int j = 0;j<column;j++)
                    cout << data[i][j] << " ";
                cout << endl;
            }
        }
        const Matrix add(const Matrix<T>& other)
        {
            Matrix<T> result(other.getRow(),other.getColumn());
            for(int i = 0;i<result.getRow();i++)
            {
                for(int j = 0;j<result.getColumn();j++)
                    result.setElement(i,j,other.getData(i,j)+this->data[i][j]);
                cout << endl;
            }
            return result;
        }

        const int getRow()const{return row;}
        const int getColumn()const{return column;}
    private:
        unique_ptr<unique_ptr<T[]>[]>data;
        int row,column;
};


int main() {
    // Step 1: Create two matrices (3x3)
    Matrix<int> matrix1(3, 3);
    Matrix<int> matrix2(3, 3);

    // Step 2: Set values for matrix1
    std::cout << "Setting values for matrix1...\n";
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            matrix1.setElement(i, j, (i + 1) * (j + 1)); // Example: Fill with multiplication table
        }
    }

    // Step 3: Set values for matrix2
    std::cout << "Setting values for matrix2...\n";
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            matrix2.setElement(i, j, (i + 1) + (j + 1)); // Example: Fill with addition table
        }
    }

    // Step 4: Print both matrices
    std::cout << "Matrix 1:\n";
    matrix1.print();

    std::cout << "\nMatrix 2:\n";
    matrix2.print();

    // Step 5: Add the two matrices and print the result
    std::cout << "\nAdding matrix1 and matrix2...\n";
    Matrix result = matrix1.add(matrix2);

    std::cout << "Resultant Matrix:\n";
    result.print();

    return 0;
}
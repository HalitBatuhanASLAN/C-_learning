#include <iostream>
using namespace std;
#include"matrix3d.h"

int main() {
    // Create a 2x2 matrix
    Matrix mat1(2,2);
    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(1, 0, 3);
    mat1.setElement(1, 1, 4);

    // Create another 2x2 matrix and set elements
    Matrix mat2(2, 2);
    mat2.setElement(0, 0, 5);
    mat2.setElement(0, 1, 6);
    mat2.setElement(1, 0, 7);
    mat2.setElement(1, 1, 8);
    // Matrix addition
    Matrix mat3 = mat1 + mat2;
    cout << "Matrix Addition:\n" << mat3 << endl;

    // Input a matrix
    Matrix mat5(2, 2);
    cout << "Enter a 2x2 matrix:\n";
    cin >> mat5;
    cout << "You entered:\n" << mat5;

    return 0;
}

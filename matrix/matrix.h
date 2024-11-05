#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;

class Matrix
{
    public:
        Matrix(int i,int c);
        ~Matrix();

        Matrix operator+(Matrix& tmp);
        Matrix& operator=(const Matrix& other);
        friend ostream& operator<<(ostream& out,Matrix& tmp);
        friend istream& operator>>(istream& in,Matrix& tmp);

        int operator()(int i,int j);

        void setElement(int i, int j,int value){element[i][j] = value;}
        int getElement(int i,int j){return element[i][j];}
        int getLine(){return line;}
        int getColumn(){return column;}
    private: 
        int line;
        int column;
        int** element;
};


#endif
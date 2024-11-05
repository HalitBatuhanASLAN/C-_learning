#include<iostream>
#include"matrix3d.h"

Matrix::Matrix(int l, int c):line(l),column(c)
{
    element = new int*[line];
    for(int i = 0;i<line;i++)
        element[i] = new int[column];
}
Matrix::~Matrix()
{
    for(int i = 0;i<line;i++)
        delete[] element[i];
    delete[] element;
}

Matrix Matrix::operator+(Matrix& tmp)
{
    if(tmp.getLine() != getLine() || tmp.getColumn() != getColumn())
        exit(-1);
    Matrix res(getLine(),getColumn());
    for(int i = 0;i<getLine();i++)
    {
        for(int j = 0;j<getColumn();j++)
            res.setElement(i,j,getElement(i,j) + tmp.getElement(i,j));
    }
    return res;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this == &other) return *this; // Self-assignment check

    // Step 1: Deallocate existing memory if necessary
    for (int i = 0; i < line; ++i) {
        delete[] element[i];
    }
    delete[] element;

    // Step 2: Copy dimensions and allocate new memory
    line = other.line;
    column = other.column;
    element = new int*[line];
    for (int i = 0; i < line; ++i) {
        element[i] = new int[column];
        for (int j = 0; j < column; ++j)
            element[i][j] = other.element[i][j];
    }
    return *this;
}

ostream& operator<<(ostream& out,Matrix& tmp)
{
    for(int i = 0;i<tmp.getLine();i++)
    {
        for(int j = 0;j<tmp.getColumn();j++)
            out << tmp.getElement(i,j) << " ";
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in,Matrix& tmp)
{
    int value;
    for(int i = 0;i<tmp.getLine();i++)
    {
        for(int j = 0;j<tmp.getColumn();j++)
        {
            in >> value;
            tmp.setElement(i,j,value);
        }
    }
    return in;
}

int Matrix::operator()(int i,int j)
{
    if(i < 0 || i>= getLine() || j < 0 || j>getColumn())
        exit(-1);
    return element[i][j];
}
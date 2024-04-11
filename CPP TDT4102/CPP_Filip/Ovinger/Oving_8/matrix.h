#pragma once
#include <iostream>
#include <assert.h>  
using namespace std;

class Matrix{
private:
    int rows;
    int columns;
    double** matrix;

public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();

    double get(int row, int col) const;
    void set(int row, int col, double value);
    double* operator[](int row);
    int getRows() const;
    int getColumns() const;
    friend ostream& operator << (ostream& os, Matrix& matrise);

    Matrix(const Matrix &other);
    Matrix &operator=(Matrix& rhs);

    Matrix &operator+=(Matrix rhs);
    Matrix operator+(Matrix& rhs);
    
};
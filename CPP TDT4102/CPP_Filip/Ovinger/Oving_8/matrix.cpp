#include "matrix.h"

Matrix::Matrix(int nRows, int nColumns): rows{nRows}, columns{nColumns} {
        assert(nColumns >= 0);
        assert(nRows >= 0);

        matrix = new double*[nRows];
        for (int i = 0; i < nRows; i++) {
            matrix[i] = new double[nColumns];
            for (int j = 0; j < nColumns; j++) {
                matrix[i][j] = 0.0;
            }
        }
    }   

//delegerende konstruktør
Matrix::Matrix(int nRows): Matrix(nRows, nRows) {
        for (int i = 0; i < nRows; i++){
            matrix[i][i] = 1.0;
        }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

double Matrix::get(int row, int col) const{
    double toReturn = matrix[row][col];
    return toReturn;
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}

double* Matrix::operator[](int row){
    return matrix[row];
}

int Matrix::getRows() const{
    return rows;
}

int Matrix::getColumns() const{
    return columns;
}

ostream& operator << (ostream& os, Matrix& matrise){
    for (int i = 0; i < matrise.rows ; i++){
		for (int j = 0; j < matrise.columns ; j++) {
			os << matrise.matrix[i][j] << ' ';
		}
		os << '\n';
    }
    return os;
}

Matrix::Matrix(const Matrix &other) : matrix{nullptr} {
    rows = other.rows;
    columns = other.columns;
    matrix = new double*[other.rows];
        for (int i = 0; i < other.rows; i++) {
            matrix[i] = new double[other.columns];
            for (int j = 0; j < other.columns; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
}

Matrix &Matrix::operator=(Matrix& rhs){
    swap(rows, rhs.rows);
    swap(columns, rhs.columns);
    swap(matrix, rhs.matrix);
    return *this;
}

Matrix &Matrix::operator+=(Matrix rhs) {
    assert(rows = rhs.rows);
    assert(columns = rhs.columns);
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix& rhs) {
    assert(rows = rhs.rows);
    assert(columns = rhs.columns);
    Matrix copyMatrix{*this};
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < columns; j++) {
            copyMatrix.matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return copyMatrix;
}
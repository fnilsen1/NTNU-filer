#include "Stopwatch.h"
#include <vector>
#include <iostream>

// Utdelt kode til oppgave 3

//Itererer gjennom diagonalen i stedet (1 for loop)
void setDiagonalValue(std::vector<std::vector<double>>& matrix, double newValue){
    for (int i = 0; i < matrix.size(); i++){
        matrix[i][i]=newValue;
    }
}

//Itererer gjennom rader og så kolonner. Da ligger elementene nærme hverandre i minnet: Cache
double sumMatrix(std::vector<std::vector<double>> matrix){
    double sum;
    for (int row = 0; row < matrix.size(); row++){
        for (int col = 0; col < matrix.size(); col++){
            sum += matrix[row][col];            
        }
    }
    return sum;
}

void optimizationTask() {
    
    const int matrixSize = 10000;

    // Create a matrix with zeros
    std::vector<std::vector<double>> matrix;
    
    //Bruker resize i stedet for loop
    for (int i = 0; i < matrixSize; i++){
        std::vector<double> column;
        column.resize(matrixSize);
        matrix.push_back(column);
    }

    // Set all elements on the diagonal to 0.41
    setDiagonalValue(matrix, 0.41);
    
    // Sum all elements in the matrix
    double total = sumMatrix(matrix);

    double coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;
}
#include "Tetromino.h"
#include <map>
#include <iostream>
#include "AnimationWindow.h"
using namespace std;
    
const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {

    {
    TetrominoType::J,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
        }
    },

        { 
    TetrominoType::Z, 
        {
        {0, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
        }
    },

    { 
    TetrominoType::T, 
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
        }
    },
    { 
    TetrominoType::S, 
        {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 0}
        }
    },
    { 
    TetrominoType::I, 
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
        }
    },

    { 
    TetrominoType::L, 
        {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
        }
    },


    { 
    TetrominoType::O, 
        {
        {1, 1},
        {1, 1}
        }
    },
    {

    
}};




Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : 
topLeftCorner{startingPoint}, 
matrixSize{static_cast<int>(initialMatrixMap.at(tetType).size())},
blockMatrix(matrixSize, vector<TetrominoType>(matrixSize, TetrominoType::NONE))
{

for(int rows = 0; rows < matrixSize; rows++){
for(int columns = 0; columns < matrixSize; columns++){
if(initialMatrixMap.at(tetType)[rows][columns]==1){
blockMatrix.at(rows).at(columns)=tetType;
}


}

}

}

Tetromino::Tetromino(){
topLeftCorner = {0,0};
matrixSize = 0;
};

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}

void Tetromino::moveDown(){
topLeftCorner.y+=blockSize;


}

void Tetromino::moveUp(){


topLeftCorner.y-=blockSize;

}

void Tetromino::moveLeft(){
topLeftCorner.x-=blockSize;
}

void Tetromino::moveRight(){
topLeftCorner.x+=blockSize;
}

bool Tetromino::blockExist(int row, int column){
if (row < 0 || row >= blockMatrix.size()) {
    cout << "Indeks er utenfor matrisen" << endl;
    return false;
}

return blockMatrix[row][column] != TetrominoType::NONE;
}

TetrominoType Tetromino::getBlock(int row, int column){
    return blockMatrix[row][column];
}

int Tetromino::getMatrixSize(){
    return matrixSize;
}

TDT4102::Point Tetromino::gettopLeftCorner(){
    return topLeftCorner;
}

void Tetromino::printMatrix() {
    for (int row = 0; row < matrixSize; ++row) {
        for (int col = 0; col < matrixSize; ++col) {
            cout << (blockMatrix[row][col] != TetrominoType::NONE ? "X" : "O");
        }
        cout << endl;
    }
}


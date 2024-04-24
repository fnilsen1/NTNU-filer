#pragma once
#include <vector>
#include <map>
#include "AnimationWindow.h"

enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

const std::map<TetrominoType, TDT4102::Color> tetrominoColors {
    { TetrominoType::J, TDT4102::Color::blue },
    { TetrominoType::Z, TDT4102::Color::red },
    { TetrominoType::T, TDT4102::Color::purple },
    { TetrominoType::S, TDT4102::Color::green },
    { TetrominoType::I, TDT4102::Color::cyan },
    { TetrominoType::L, TDT4102::Color::orange },
    { TetrominoType::O, TDT4102::Color::yellow },
    { TetrominoType::NONE, TDT4102::Color::white}
};

class Tetromino {
public:
    static constexpr int blockSize {30};

    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);
    
    Tetromino();

    void rotateClockwise();
    void rotateCounterClockwise();
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();

    bool blockExist(int row, int column);
    TetrominoType getBlock(int row, int column);
    int getMatrixSize();
    TDT4102::Point gettopLeftCorner();

    void printMatrix();


private: 
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};  
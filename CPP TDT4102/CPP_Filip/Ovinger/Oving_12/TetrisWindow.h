#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <vector>


using namespace std;

class TetrisWindow : public TDT4102::AnimationWindow {

public:
    TetrisWindow();
    void run();
    


private:
    const int windowHeight = 20;
    const int windowWidth = 10;
    const int blockSize = 30;
    const TDT4102::Point startPoint = {0, 0};




    vector<vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;


    void handleInput();
    void generateRandomTetromino();
    void drawCurrentTetromino();
    void moveTetrominoDown();
    void fastenTetromino();
    void drawGridMatrix();
    bool hasCrashed();

};

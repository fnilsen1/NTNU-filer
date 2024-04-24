#include "TetrisWindow.h"
#include <iostream>
#include <vector>
#include <random>
#include "AnimationWindow.h"
#include "Tetromino.h"
using namespace std;



TetrisWindow::TetrisWindow():
AnimationWindow{100, 100, 300, 600, "Tetris"},
currentTetromino{},
gridMatrix(windowHeight, vector<TetrominoType>(windowWidth, TetrominoType::NONE))
{
generateRandomTetromino();    

}

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 60;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            //Kall moveTetrominoDown() her
            moveTetrominoDown();
            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        //Kall draw-funksjonene her
        drawGridMatrix();
        drawCurrentTetromino();
        
        /********************************************************/

        next_frame();
    }
}


void TetrisWindow::handleInput() {


    static bool lastUpKeyState = false;
    static bool lastDownKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastZKeyState = false;

    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentZKeyState = is_key_down(KeyboardKey::Z);




    if(currentRightKeyState && !lastRightKeyState) {
        currentTetromino.moveRight();
        if(hasCrashed()){
            currentTetromino.moveLeft();
        }
        
    }

    if(currentLeftKeyState && !lastLeftKeyState) {
        currentTetromino.moveLeft();

            if(hasCrashed()){
            currentTetromino.moveRight();
        }
    }

        
    if(currentDownKeyState && !lastDownKeyState) {
        currentTetromino.moveDown();
        if(hasCrashed()){
        currentTetromino.moveUp();
        }
    }

    if(currentUpKeyState && !lastUpKeyState) {
        currentTetromino.rotateClockwise();
        if(hasCrashed()){
        currentTetromino.rotateCounterClockwise();
        }
    }

    if(currentZKeyState && !lastZKeyState) {
        currentTetromino.rotateCounterClockwise();
        if(hasCrashed()){
        currentTetromino.rotateClockwise();
        }
    }


    lastUpKeyState = currentUpKeyState;
    lastDownKeyState = currentDownKeyState;
    lastRightKeyState = currentRightKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastZKeyState = currentZKeyState;

}



void TetrisWindow::generateRandomTetromino(){

random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<int> distribution(0, 6);
currentTetromino = Tetromino{startPoint, static_cast<TetrominoType>(distribution(generator))};
}


void TetrisWindow::drawCurrentTetromino() {
    
    int matrixSize = currentTetromino.getMatrixSize();
    TDT4102::Point corner = currentTetromino.gettopLeftCorner();

    for(int i=0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++) {
        
        corner = {currentTetromino.gettopLeftCorner().x+(blockSize*j), currentTetromino.gettopLeftCorner().y+(blockSize*i)};
        if(currentTetromino.blockExist(i, j)){
            draw_rectangle(corner, blockSize, blockSize, tetrominoColors.at(currentTetromino.getBlock(i, j)));
        }
        

        }
    }
}

void TetrisWindow::moveTetrominoDown(){
currentTetromino.moveDown();


if(hasCrashed()){
currentTetromino.moveUp();
fastenTetromino();
generateRandomTetromino();

}




}

void TetrisWindow::fastenTetromino(){
    TDT4102::Point corner = currentTetromino.gettopLeftCorner();
    for(int i = 0; i < currentTetromino.getMatrixSize(); i++){
        for (int j = 0; j < currentTetromino.getMatrixSize(); j++)
        {
            if(currentTetromino.blockExist(i,j)){
                gridMatrix.at((corner.y+30*i)/30).at((corner.x+30*j)/30)=currentTetromino.getBlock(i, j);
            }
        }
    
    }
currentTetromino = Tetromino{};



}

void TetrisWindow::drawGridMatrix(){

for(int i=0; i < windowHeight; i++){
    for(int j = 0; j < windowWidth; j++) {

    draw_rectangle({j*30,i*30}, blockSize, blockSize, tetrominoColors.at(gridMatrix.at(i).at(j)));

    }
}

}

bool TetrisWindow::hasCrashed(){
    int matrixSize = currentTetromino.getMatrixSize();
    TDT4102::Point corner = currentTetromino.gettopLeftCorner();

    for(int i=0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++) {
        corner = {currentTetromino.gettopLeftCorner().x+(blockSize*j), currentTetromino.gettopLeftCorner().y+(blockSize*i)};
        if(currentTetromino.blockExist(i,j)==true && (corner.x<0 || corner.x+30>windowWidth*30 || corner.y+30>windowHeight*30)){

            return true;
        }
        if(currentTetromino.blockExist(i,j)==true && (corner.y+30*i)/30<20 && (corner.x+30*j)/30<10){
            if(gridMatrix.at((corner.y+30*i)/30).at((corner.x+30*j)/30)!=TetrominoType::NONE){
 
                return true;
            }
        }


        }
    }

    return false;
}


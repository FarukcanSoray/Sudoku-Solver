#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include "cell.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <mutex>
#include <thread>
#include <random>
#include <Eigen/Eigen>

#include <iostream>

using namespace Eigen;

class SudokuBoard
{
public:
    SudokuBoard(std::ifstream& file, int threadNum);
    int whichThread;
    Cell sudoku[9][9];
    bool solveSudoku();
    int t = 0;
//private:
    Matrix<int, 9, 9> solutionSteps;
    Matrix<int, 9, 9> firstStep;
    std::vector<std::pair<int, int>> zeroDefined;
    std::vector<std::pair<int, int>> sequence;
    std::pair<int,int> a();
    void assignPossibleNumbers();
    void assignSequence();
    std::vector<int> cutPossibleNumbersForRow(int thRow);
    std::vector<int> cutPossibleNumbersForColumn(int thColumn);
    std::vector<int> cutPossibleNumbersForSquare(int thSquareX, int thSquareY);
    bool lookForRow(int thRow, int number);
    bool lookForColumn(int thColumn, int number);
    bool lookForSquare(int thSquareX, int thSquareY, int number);
    bool isBoardFilled();
    std::mutex mtx;
};

#endif // SUDOKUBOARD_H

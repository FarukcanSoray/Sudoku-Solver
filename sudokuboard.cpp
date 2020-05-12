#include "sudokuboard.h"

SudokuBoard::SudokuBoard(std::ifstream& file, int threadNum)
{

    int number;
    char w;
    whichThread = threadNum;
    std::vector<int> defaultPossibleNumbers = {1,2,3,4,5,6,7,8,9};
    if(file.is_open())
       {
           for(int i=0;i<9;++i)
               for(int j=0;j<9;++j){
                   file >> w;
                   if(w == '*'){
                       number = 0;
                       sudoku[i][j].isDefinite = false;
                       sudoku[i][j].possibleNumbers = defaultPossibleNumbers;
                       zeroDefined.push_back(std::make_pair(i,j));

                   }
                   else {number=w-'0'; sudoku[i][j].isDefinite=true;}
                   sudoku[i][j].value = number;
                   solutionSteps(i,j) = number;
                }
           firstStep = solutionSteps;
            assignSequence();
            assignPossibleNumbers();
            file.close();
       }
}



bool SudokuBoard::solveSudoku(){



    if(isBoardFilled()){
        std::ofstream ofile("C:\\Users\\faruk\\Desktop\\sss.txt");

        ofile << solutionSteps << std::endl << std::endl;
        for(auto iter = sequence.begin(); iter != sequence.end(); ++iter){
            solutionSteps(iter->first,iter->second) = sudoku[iter->first][iter->second].value;
            ofile << solutionSteps << std::endl << std::endl;
        }
                    std::cout << "thread" << whichThread << " finished." << std::endl;
        return true;
    }
    auto iter = a();
    auto& vec = sudoku[iter.first][iter.second].possibleNumbers;
    for(auto iter2 = vec.begin(); iter2 != vec.end(); ++iter2){
        if(lookForRow(iter.first, *iter2) && lookForColumn(iter.second, *iter2) && lookForSquare(iter.first, iter.second, *iter2)){
            sudoku[iter.first][iter.second].value = *iter2;
            if(solveSudoku()){
                return true;
            }
            sudoku[iter.first][iter.second].value = 0;

        }
    }
    return false;
}

bool SudokuBoard::isBoardFilled(){
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j){
            if(sudoku[i][j].value == 0)
                return false;
        }
    return true;
}

std::pair<int,int> SudokuBoard::a(){
    for(auto iter = sequence.begin(); iter != sequence.end(); ++iter){
        if(sudoku[iter->first][iter->second].value == 0){
            return *iter;
        }
    }
}

void SudokuBoard::assignSequence(){
    while(zeroDefined.size() != 0){
         std::default_random_engine generator;
         std::uniform_int_distribution<int> distribution(0,zeroDefined.size()-1);
         std::pair<int,int> x = zeroDefined.at(distribution(generator));
         sequence.push_back(x);
         std::vector<std::pair<int,int>>::iterator p = std::find(zeroDefined.begin(), zeroDefined.end(), x);
         if(p != zeroDefined.end())
             zeroDefined.erase(p);

    }
}


bool SudokuBoard::lookForRow(int thRow, int number){
    for(int i = 0; i < 9; ++i){
        if(sudoku[thRow][i].value == number)
            return false;
    }
    return true;
}

bool SudokuBoard::lookForColumn(int thColumn, int number){
    for(int i = 0; i < 9; ++i){
        if(sudoku[i][thColumn].value == number)
            return false;
    }
    return true;
}

bool SudokuBoard::lookForSquare(int thSquareX, int thSquareY, int number){
    int x = thSquareX - (thSquareX % 3);
    int y = thSquareY - (thSquareY % 3);
    for(int i = y; i < y+3; ++i)
        for(int j = x; j < x+3; ++j){
            if(sudoku[j][i].value == number)
                return false;
        }
    return true;
}

void SudokuBoard::assignPossibleNumbers(){
    std::vector<int>::iterator p;
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j){

            if(!sudoku[i][j].isDefinite){
                std::vector<int> rowLine = cutPossibleNumbersForRow(i);
                std::vector<int> columnLine = cutPossibleNumbersForColumn(j);
                std::vector<int> square = cutPossibleNumbersForSquare(i,j);
                for(auto iter = rowLine.begin(); iter != rowLine.end(); ++iter){
                      p = std::find (sudoku[i][j].possibleNumbers.begin(), sudoku[i][j].possibleNumbers.end(), *iter);
                     if (p != sudoku[i][j].possibleNumbers.end())
                       sudoku[i][j].possibleNumbers.erase(p);
                }
                for(auto iter = columnLine.begin(); iter != columnLine.end(); ++iter){
                     p = std::find (sudoku[i][j].possibleNumbers.begin(), sudoku[i][j].possibleNumbers.end(), *iter);
                     if (p != sudoku[i][j].possibleNumbers.end())
                     sudoku[i][j].possibleNumbers.erase(p);
                }
                for(auto iter = square.begin(); iter != square.end(); ++iter){
                     p = std::find (sudoku[i][j].possibleNumbers.begin(), sudoku[i][j].possibleNumbers.end(), *iter);
                     if (p != sudoku[i][j].possibleNumbers.end())
                     sudoku[i][j].possibleNumbers.erase(p);
                }


            }
        }
   // solveSudoku();
}

std::vector<int> SudokuBoard::cutPossibleNumbersForRow(int thRow){
    std::vector<int> rowValues;
    for(int i = 0; i < 9; ++i){
        if(!sudoku[thRow][i].value == 0)
            rowValues.push_back(sudoku[thRow][i].value);
    }
    return rowValues;
}

std::vector<int> SudokuBoard::cutPossibleNumbersForColumn(int thColumn){
    std::vector<int> columnValues;
    for(int i = 0; i < 9; ++i){
        if(!sudoku[i][thColumn].value == 0)
            columnValues.push_back(sudoku[i][thColumn].value);
    }
    return columnValues;
}

std::vector<int> SudokuBoard::cutPossibleNumbersForSquare(int thSquareX, int thSquareY){
    std::vector<int> squareValues;
    int x = thSquareX - (thSquareX % 3);
    int y = thSquareY - (thSquareY % 3);
    for(int i = x; i < x+3; ++i)
        for(int j = y; j < y+3; ++j){
            if(!sudoku[i][j].value == 0)
                squareValues.push_back(sudoku[i][j].value);
        }
    return squareValues;
}

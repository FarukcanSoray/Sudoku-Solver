#ifndef CELL_H
#define CELL_H

#include <vector>

class Cell
{
    friend class SudokuBoard;
public:
    Cell();
//private:
    int value;
    std::vector<int> possibleNumbers;
    bool isDefinite;
};

#endif // CELL_H

#ifndef _SUDOKU_
#define _SUDOKU_

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Sudoku{
private:
    int sudokuNums[9][9]; // 2D Array, holds all 81 numbers for Sudoku Board
    int rows; // Constant variable for rows
    int cols; // Constant variable for columns
    bool fill(int row, int col);
    // Pre-Conditions: The public fill class was called, and private fill class returned the initial values necessary to start on the first row.
    // Post-Conditions: sudokuNums will be filled with 81 numbers, none of them the same on each row, col, and 3x3 grid. (If not, the )
    bool check(int row, int col);
    // Pre-Conditions: Private fill class has given a row and col value less than 9, the number on that row and col of the sudoku board has been given a value from 1 to 9.
    // Post-Conditions: If the number is valid, it will be placed in the sudokuNums Array, otherwise, another number is attempted. (If all 9 numbers don't work, then the program alerts you of this.)
    bool checkCol(int row, int col);
    // Pre-Conditions: The check class was called.
    // Post-Conditions: If the same number isn't anywhere throughout the column, this bool returns true.
    bool checkRow(int row, int col);
    // Pre-Conditions: The check class was called, checkCol returned true.
    // Post-Conditions: If the same number isn't anywhere throughout the row, this bool returns true.
    bool checkGrid(int row, int col);
    // Pre-Conditions: The check class was called, checkCol and checkRow returned true.
    // Post-Conditions: If the same number isn't anywhere throughout the 3x3 grid, this bool returns true.
    public:
    Sudoku(int SIZE); // Constructor, creates a Sudoku Board of the required size (A 9 by 9 Sudoku Board, in this case.)
    bool fill();
    // Pre-Conditions: None.
    // Post-Conditions: the private bool fill will be called with initial values that start us on the first column and row of the Sudoku Board.
    void printBoard();
    // Pre-Conditions: The Sudoku Board was filled and was possible to fill.
    // Post-Conditions: The Sudoku Board will be printed for the user to see. 
};
#endif 
#include "Sudoku.hpp"

Sudoku::Sudoku(int SIZE){
	rows = cols = SIZE; // Makes column and row constants equal the size of the board.
	for(int i = 0;i < SIZE;i++){
		for (int j = 0;j<SIZE;j++)
			sudokuNums[i][j] = 0; // initializes each value to zero so that comparisons are allowed even when the first numbers are being placed on the board.
	}
}
bool Sudoku::fill(){
	return fill(0 , 0); // initializes the private function with 0,0, forcing the sudoku board to start placing values
						// on the first column and row.
}
bool Sudoku::fill(int row, int col){
	if(col >= cols && row >= rows){ // if every value has been placed.
		return true; 
	}
	else if(col >= cols){ // if a column is finished, move to the next row.
		return fill(row + 1 ,col - 9);
	}
	else{
    	int cell = rand() % 9 + 1;
    	for (int i = 0; i < 9; i++){ // this loop checks all numbers from 1 - 9 if the first value doesn't work. If none of the numbers work, the sudoku board can't be made.
    		if(cell + i > 9){
    			cell = -i+1; // will make the answer 1 to RAND - 1 from this point onwards, checking every solution
    			sudokuNums[row][col] = cell + i;
    		}
    		else
    			sudokuNums[row][col] = cell + i;
        	if(check(row, col) && fill(row,col+1)) // moves to the next column if the number is valid
        	    return true; 
        	else
            sudokuNums[row][col] = 0;
    	}
    return false; // All nine values have been tested and didn't work.
	}
}	
bool Sudoku::check(int row, int col){
	if(!checkCol(row , col))
		return false;
	else if(!checkRow(row , col))
		return false;
	else if(!checkGrid(row , col))
		return false;

	return true;
}
bool Sudoku::checkCol(int row, int col){
	for(int i = 0; i < cols;i++)
		if (i != col && sudokuNums[row][col] == sudokuNums[row][i])
			return false;

	return true;
}
bool Sudoku::checkRow(int row, int col){
	for (int i = 0; i < rows;i++)
		if(i != row && sudokuNums[row][col] == sudokuNums[i][col])
			return false;

	return true;
}
bool Sudoku::checkGrid(int row, int col){
	for (int i = (row / 3) * 3; i < (((row / 3) * 3) + 3); i++){ //Due to integer division when programming, this formula allows us to always have 3 by 3 barriers for each 3x3 grid
		for(int j = (col / 3) * 3; j < (((col / 3) * 3) + 3); j++){
			if(i != row || j != col){
				if(sudokuNums[row][col] == sudokuNums[i][j])
					return false;
			}
		}
	}
	return true;
}
void Sudoku::printBoard(){	
	cout << "  ===================================" << endl;
	cout << " | " << sudokuNums[0][0] << "   "<< sudokuNums[0][1] << "   "<< sudokuNums[0][2] << " | "<< sudokuNums[0][3] << "   "<< sudokuNums[0][4] << "   "<< sudokuNums[0][5] << " | " << sudokuNums[0][6] << "   " << sudokuNums[0][7] << "   " << sudokuNums[0][8] << " | \n"
		 << endl; 
	cout << " | " << sudokuNums[1][0] << "   "<< sudokuNums[1][1] << "   "<< sudokuNums[1][2] << " | "<< sudokuNums[1][3] << "   "<< sudokuNums[1][4] << "   "<< sudokuNums[1][5] << " | " << sudokuNums[1][6] << "   " << sudokuNums[1][7] << "   " << sudokuNums[1][8] << " | \n"
		 << endl; 
	cout << " | " << sudokuNums[2][0] << "   "<< sudokuNums[2][1] << "   "<< sudokuNums[2][2] << " | "<< sudokuNums[2][3] << "   "<< sudokuNums[2][4] << "   "<< sudokuNums[2][5] << " | " << sudokuNums[2][6] << "   " << sudokuNums[2][7] << "   " << sudokuNums[2][8] << " | \n"
		 << "  ===================================" << endl;
	cout << " | " << sudokuNums[3][0] << "   "<< sudokuNums[3][1] << "   "<< sudokuNums[3][2] << " | "<< sudokuNums[3][3] << "   "<< sudokuNums[3][4] << "   "<< sudokuNums[3][5] << " | " << sudokuNums[3][6] << "   " << sudokuNums[3][7] << "   " << sudokuNums[3][8] << " | \n"
		 << endl; 
	cout << " | " << sudokuNums[4][0] << "   "<< sudokuNums[4][1] << "   "<< sudokuNums[4][2] << " | "<< sudokuNums[4][3] << "   "<< sudokuNums[4][4] << "   "<< sudokuNums[4][5] << " | " << sudokuNums[4][6] << "   " << sudokuNums[4][7] << "   " << sudokuNums[4][8] << " | \n"
		 << endl; 
	cout << " | " << sudokuNums[5][0] << "   "<< sudokuNums[5][1] << "   "<< sudokuNums[5][2] << " | "<< sudokuNums[5][3] << "   "<< sudokuNums[5][4] << "   "<< sudokuNums[5][5] << " | " << sudokuNums[5][6] << "   " << sudokuNums[5][7] << "   " << sudokuNums[5][8] << " | \n"
		 << "  ===================================" << endl;
	cout << " | " << sudokuNums[6][0] << "   "<< sudokuNums[6][1] << "   "<< sudokuNums[6][2] << " | "<< sudokuNums[6][3] << "   "<< sudokuNums[6][4] << "   "<< sudokuNums[6][5] << " | " << sudokuNums[6][6] << "   " << sudokuNums[6][7] << "   " << sudokuNums[6][8] << " | \n"
		 << endl; 
	cout << " | " << sudokuNums[7][0] << "   "<< sudokuNums[7][1] << "   "<< sudokuNums[7][2] << " | "<< sudokuNums[7][3] << "   "<< sudokuNums[7][4] << "   "<< sudokuNums[7][5] << " | " << sudokuNums[7][6] << "   " << sudokuNums[7][7] << "   " << sudokuNums[7][8] << " | \n"
		 << endl; 
	cout << " | " << sudokuNums[8][0] << "   "<< sudokuNums[8][1] << "   "<< sudokuNums[8][2] << " | "<< sudokuNums[8][3] << "   "<< sudokuNums[8][4] << "   "<< sudokuNums[8][5] << " | " << sudokuNums[8][6] << "   " << sudokuNums[8][7] << "   " << sudokuNums[8][8] << " | \n"
		 << "  ===================================" << endl;
}

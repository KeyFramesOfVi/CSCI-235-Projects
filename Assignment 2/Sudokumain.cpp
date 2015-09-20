#include "Sudoku.hpp"

using namespace std;
int main(){
    srand(time(NULL));
	Sudoku Brizan(9); // Hi Brizan!
	if(!Brizan.fill()){ // Will close automatically if Sudoku board cannot be made
		cout << "Sudoku Board cannot be made." << endl;
        return 0;
	}
	Brizan.printBoard(); // Here's your Sudoku Board!
	exit(1);
	return 0;
}
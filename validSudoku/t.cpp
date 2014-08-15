/*
   Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

   The Sudoku board could be partially filled, where empty cells are filled
   with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the
filled cells need to be validated.
*/

#include <vector>
#include <iostream>
#include <strings.h> // for'bzero'
using namespace std;

class Solution {
public:
     bool isValidSudoku(vector<vector<char> > &board) {
         int i, j;

	 // check every row
         int filled[9];
	 for (i = 0; i < 9; i++) {
	     bzero(filled, 9*sizeof(int));
	     for (int k = 0; k < 9; k++) {
		 if (board[i][k] != '.') {
		     if (filled[board[i][k]-'1']) return false;
		     filled[board[i][k]-'1'] = 1;
		 }
	     }
         }
	 // check every column
	 for (i = 0; i < 9; i++) {
	     bzero(filled, 9*sizeof(int));
	     for (int k = 0; k < 9; k++) {
		 if (board[k][i] != '.') {
		     if (filled[board[k][i]-'1']) return false;
		     filled[board[k][i]-'1'] = 1;
		 }
	     }
         }
	 // check every 3x3 block
	 for (i = 0; i < 9; i += 3) {
	     for (j = 0; j < 9; j += 3) {
		 bzero(filled, 9*sizeof(int));
		 for (int k = i; k < i + 3; k++) {
		     for (int p = j; p < j + 3; p++) {
			 if (board[k][p] != '.') {
			     if (filled[board[k][p]-'1']) return false;
			     filled[board[k][p]-'1'] = 1;
			 }
		     }
		 }
	     }
	 }

	 return true;
     }
};

int main()
{
    Solution s;
    bool ret;
    vector<vector<char>> board = {
                                   {'5','3','.','.','7','.','.','.','.'},
                                   {'6','.','.','1','9','5','.','.','.'},
                                   {'.','9','8','.','.','.','.','6','.'},
                                   {'8','.','.','.','6','.','.','.','3'},
                                   {'4','.','.','8','.','3','.','.','1'},
                                   {'7','.','.','.','2','.','.','.','6'},
                                   {'.','6','.','.','.','.','2','8','.'},
                                   {'.','.','.','4','1','9','.','.','5'},
                                   {'.','.','.','.','8','.','.','7','9'}
                                 };

    ret = s.isValidSudoku(board);
    cout << ret << endl;
}

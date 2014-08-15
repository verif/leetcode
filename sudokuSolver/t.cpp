/*
   Write a program to solve a Sudoku puzzle by filling the empty cells.
   Empty cells are indicated by the character '.'.
   You may assume that there will be only one unique solution.
*/

#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
     bool fillNextEntry(vector<vector<char>> &board) {
         int i, j;
         bool ret = true;
         for (i = 0; i < 9; i++) {
             for (j = 0; j < 9; j++) {
                 if (board[i][j] == '.') {
                     ret = false;
                     break;
                 }
             }
             if (!ret) break;
         }

         if (ret) return true;

         bool filled[9] = {false};
         // check row/col/3x3 block to find available numbers
         for (int k = 0; k < 9; k++) {
             if (board[i][k] != '.') {
                 filled[board[i][k]-'1'] = true;
             }
             if (board[k][j] != '.') {
                 filled[board[k][j]-'1'] = true;
             }
         }
         int bcol, brow; // 3x3 block left corner row & col
         brow = i - (i % 3); 
         bcol = j - (j % 3);
         for (int k = brow; k < brow + 3; k++) {
             for (int p = bcol; p < bcol + 3; p++) {
                 if (board[k][p] != '.') {
                     filled[board[k][p]-'1'] = true;
                 }
             }
         }

         // Now fill the entry
         for (int k = 0; k < 9; k++) {
             if (!filled[k]) {
                 board[i][j] = k+'1';
                 bool done = fillNextEntry(board);
                 if (done) return true;
                 board[i][j] = '.';
             }
         }
         return false;
     }

     void solveSudoku(vector<vector<char>> &board) {
         assert(board.size() == 9);
         assert(board[0].size() == 9);
         fillNextEntry(board);
     }
};

int main()
{
    Solution s;
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

    s.solveSudoku(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << ",";
        }
        cout << endl;
    }
}

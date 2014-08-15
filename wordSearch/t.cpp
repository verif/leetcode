/*
   Given a 2D board and a word, find if the word exists in the grid.
   The word can be constructed from letters of sequentially adjacent cell,
   where "adjacent" cells are those horizontally or vertically neighboring. The
   same letter cell may not be used more than once.

   For example,
   Given board =
   [
     ["ABCE"],
     ["SFCS"],
     ["ADEE"]
   ]
   word = "ABCCED", -> returns true,
   word = "SEE", -> returns true,
   word = "ABCB", -> returns false.
*/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
     bool findString(vector<vector<char> > &board, string& str, int row, int
                     col, int index, vector<vector<bool>>& mask)
     {
         if (board[row][col] != str[index]) return false;
         if (index == str.length()-1) return true;

         mask[row][col] = true;
         if (row < board.size()-1 && !mask[row+1][col] &&
             findString(board, str, row+1, col, index+1, mask)) {
             return true;
         }
         if (row > 0 && !mask[row-1][col] &&
             findString(board, str, row-1, col, index+1, mask)) {
             return true;
         }
         if (col < board[0].size()-1 && !mask[row][col+1] &&
             findString(board, str, row, col+1, index+1, mask)) {
             return true;
         }
         if (col > 0 && !mask[row][col-1] &&
             findString(board, str, row, col-1, index+1, mask)) {
             return true;
         }
         mask[row][col] = false;

         return false;
     }
     bool exist(vector<vector<char> > &board, string word) {
         if (!word.length()) return true;
         if (!board.size()) return false;
         vector<vector<bool>> mask(board.size(), vector<bool>(board[0].size(),
                                                              false));
         if (word.length() > board.size() * board[0].size()) return false;
         for (int i = 0; i < board.size(); i++) {
             for (int j = 0; j < board[0].size(); j++) {
                 if (findString(board, word, i, j, 0, mask)) {
                     return true;
                 }
             }
         }

         return false;
     }
};

int main()
{
    Solution s;
    bool ret;
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "ABCCED";

    ret = s.exist(board, word);
    cout << ret << endl;

    word = "SEE";
    ret = s.exist(board, word);
    cout << ret << endl;

    word = "ABCB";
    ret = s.exist(board, word);
    cout << ret << endl;

    word = "";
    ret = s.exist(board, word);
    cout << ret << endl;

    word = "A";
    ret = s.exist(board, word);
    cout << ret << endl;

    word = "Z";
    ret = s.exist(board, word);
    cout << ret << endl;
}

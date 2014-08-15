/*
   The n-queens puzzle is the problem of placing n queens on an n¡Á chessboard
   such that no two queens attack each other.

   Given an integer n, return all distinct solutions to the n-queens puzzle.
   Each solution contains a distinct board configuration of the n-queens'
   placement, where 'Q' and '.' both indicate a queen and an empty space
   respectively.

   For example,
   There exist two distinct solutions to the 4-queens puzzle:
   [
    [".Q..",  // Solution 1
     "...Q",
     "Q...",
     "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
*/

#include <vector>
#include <algorithm> // for 'abs'
#include <iostream>
using namespace std;

class Solution {
public:
     void placeQueen(int rows, vector<int> A, int n,
                     vector<vector<string>>& results){
         if (rows == n) {
             vector<string> result(n, string(n, '.'));
             for (int i = 0; i < n; i++) {
                 result[i][A[i]] = 'Q';
             }
             results.push_back(result);
             return;
         }
         for (int i = 0; i < n; i++) {
             bool valid = true;
             for (int j = 0; j < rows; j++) {
                 if (i == A[j] || abs(i-A[j]) == abs(rows-j)) {
                     valid = false;
                     break;
                 }
             }
             if (valid) {
                 A[rows] = i;
                 placeQueen(rows+1, A, n, results);
             }
         }
     }
     vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ret;
         vector<int> A(n);

         placeQueen(0, A, n, ret);

         return ret;
     }
};

int main()
{
    Solution s;
    vector<vector<string>> ret;

    ret = s.solveNQueens(8);

    for (int i = 0; i < ret.size(); i++) {
        cout << "Solution: " << i+1 << endl;
        for (int j = 0; j < ret[i].size(); j++) {
            cout << "   " << ret[i][j] << endl;
        }
        cout << endl;
    }
}

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
    void placeQueen(int n, vector<string> &cur, vector<vector<string>> &res) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        for (int col = 0; col < n; col++) {
            string str;
            bool invalid = false;
            for (int i = 0; i < cur.size(); i++) {
                int idx;
                for (idx = 0; idx < n; idx++) if (cur[i][idx] == 'Q') break;
                if (idx == col || std::abs(col-idx) == std::abs(cur.size()-i)) {
                    invalid = true;
                    break;
                }
            }
            if (!invalid) {
                for (int i = 0; i < n; i++) str.push_back('.');
                str[col] = 'Q';
                cur.push_back(str);
                placeQueen(n, cur, res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur;
        placeQueen(n, cur, res);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ret;

    ret = s.solveNQueens(4);

    for (int i = 0; i < ret.size(); i++) {
        cout << "Solution: " << i+1 << endl;
        for (int j = 0; j < ret[i].size(); j++) {
            cout << "   " << ret[i][j] << endl;
        }
        cout << endl;
    }
}

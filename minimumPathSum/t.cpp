/*
   Given a m x n grid filled with non-negative numbers, find a path from top
   left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <vector>
#include <iostream>
#include <algorithm> // for 'min'
using namespace std;

// dynamic programming should solve the problem here
class Solution {
public:
     int minPathSum(vector<vector<int>> &grid) {
         int m = grid.size();
         if (!m) return 0;
         int n = grid[0].size();
         if (!n) return 0;

         int p[m][n];

         for (int i = m-1; i >= 0; i--) {
             for (int j = n-1; j >= 0; j--) {
                 if (i == m-1 && j == n-1) {
                     p[m-1][n-1] = grid[m-1][n-1];
                 }
                 else if (i == m-1) {
                     p[i][j] = p[i][j+1] + grid[i][j];
                 }
                 else if (j == n-1) {
                     p[i][j] = p[i+1][j] + grid[i][j];
                 }
                 else {
                     p[i][j] = min(p[i+1][j], p[i][j+1]) + grid[i][j];
                 }
             }
         }
         return p[0][0];
     }
};

int main()
{
    Solution s;
    int ret;
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}, {7,8,9}};

    ret = s.minPathSum(grid);
    cout << ret << endl;
}

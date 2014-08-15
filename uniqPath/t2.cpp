/*
   Follow up for "Unique Paths":
   Now consider if some obstacles are added to the grids. How many unique paths
   would there be?

   An obstacle and empty space is marked as 1 and 0 respectively in the grid.
   For example,
   There is one obstacle in the middle of a 3x3 grid as illustrated below.
   [
     [0,0,0],
     [0,1,0],
     [0,0,0]
   ]
   The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
         int m = obstacleGrid.size();
         if (!m) return 0;
         int n = obstacleGrid[0].size();
         if (!n) return 0;

         int p[m][n];

         for (int i = m-1; i >= 0; i--) {
             for (int j = n-1; j >= 0; j--) {
                 if (obstacleGrid[i][j] == 1) {
                     p[i][j] = 0;
                 }
                 else if (i == m-1 && j == n-1) {
                     p[i][j] = 1;
                 }
                 else if (i == m-1) {
                     p[i][j] = p[i][j+1];
                 }
                 else if (j == n-1) {
                     p[i][j] = p[i+1][j];
                 }
                 else {
                     p[i][j] = p[i+1][j] + p[i][j+1];
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
    vector<vector<int> > obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    ret = s.uniquePathsWithObstacles(obstacleGrid);

    cout << ret << endl;
}

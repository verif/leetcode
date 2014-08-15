/*
   A robot is located at the top-left corner of a m x n grid (marked 'Start' in
   the diagram below).

   The robot can only move either down or right at any point in time. The robot
   is trying to reach the bottom-right corner of the grid (marked 'Finish' in
   the diagram below).

   How many possible unique paths are there?


   *** Graph missing ***


   Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

#include <iostream>
using namespace std;

// dynamic programming is a good solution here
class Solution {
public:
     int uniquePaths(int m, int n) {
         if (!m || !n) return 0;

         int p[m][n];

         for (int i = m-1; i >= 0; i--) {
             for (int j = n-1; j >= 0; j--) {
                 if (i == m-1 && j == n-1) {
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

    ret = s.uniquePaths(3, 3);
    cout << ret << endl;
}

/*
   Write an efficient algorithm that searches for a value in an m x n matrix.
   This matrix has the following properties:
   Integers in each row are sorted from left to right.
   The first integer of each row is greater than the last integer of the
   previous row.

   For example,
   Consider the following matrix:
   [
     [1,   3,  5,  7],
     [10, 11, 16, 20],
     [23, 30, 34, 50]
   ]
         Given target = 3, return true.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     bool searchMatrix(vector<vector<int> > &matrix, int target) {
         int rows = matrix.size();
         if (!rows) return false;
         int cols = matrix[0].size();
         if (!cols) return false;

         if (target < matrix[0][0] || target > matrix[rows-1][cols-1]) {
             return false;
         }
         int begin = 0;
         int end = rows-1;
         int targetRow = rows/2;
         while (matrix[targetRow][0] > target || matrix[targetRow][cols-1]
                  < target) {
             if (matrix[targetRow][0] > target) {
                 end = targetRow-1;
                 targetRow = (begin+targetRow)/2;
             }
             else {
                 begin = targetRow+1;
                 targetRow = (targetRow+end+1)/2;
             }
             if (begin > end) return false;
         }

         if (matrix[targetRow][0] == target || matrix[targetRow][cols-1] ==
             target) {
             return true;
         }

         int targetCol = cols/2;
         begin = 0;
         end = cols - 1;
         while (targetCol > 0 || targetCol < (cols-1)) {
             if (matrix[targetRow][targetCol] == target) return true;
             if (matrix[targetRow][targetCol] > target) {
                 end = targetCol-1;
                 targetCol = (begin+targetCol)/2;
             }
             else {
                 begin = targetCol+1;
                 targetCol = (end+targetCol+1)/2;
             }
             if (begin > end) return false;
         }
         
         return false;
     }
};

int main()
{
    Solution s;
    bool ret;
    vector<vector<int>> matrix = {{1}, {3}};
    //vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};

    ret = s.searchMatrix(matrix, 1);
    cout << ret << endl;

    return 0;
}


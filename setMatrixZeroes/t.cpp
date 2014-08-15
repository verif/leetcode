/*
   Given a m x n matrix, if an element is 0, set its entire row and column to
   0. Do it in place.

   click to show follow up.

   Follow up:
   Did you use extra space?
   A straight forward solution using O(mn) space is probably a bad idea.
   A simple improvement uses O(m + n) space, but still not the best solution.
   Could you devise a constant space solution?
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     void setZeroes(vector<vector<int> > &matrix) {
         bool firstRowZero = false;
         bool firstColZero = false;

         int rows = matrix.size();
         if (!rows) return;
         int cols = matrix[0].size();
         if (!cols) return;

         int i,j;

         for (i = 0; i < rows; i++) {
             if (!matrix[i][0]) {
                 firstColZero = true;
                 break;
             }
         }
         for (i = 0; i < cols; i++) {
             if (!matrix[0][i]) {
                 firstRowZero = true;
                 break;
             }
         }

         for (i = 1; i < rows; i++) {
             for (j = 1; j < cols; j++) {
                 if (!matrix[i][j]) {
                     matrix[i][0] = 0;
                     matrix [0][j] = 0;
                 }
             }
         }

         for (i = 1; i < rows; i++) {
             if (!matrix[i][0]) {
                 for (j = 1; j < cols; j++) {
                     matrix[i][j] = 0;
                 }
             }
         }
         for (i = 1; i < cols; i++) {
             if (!matrix[0][i]) {
                 for (j = 1; j < rows; j++) {
                     matrix[j][i] = 0;
                 }
             }
         }
         if (firstRowZero) {
             for (i = 0; i < cols; i++) {
                 matrix[0][i] = 0;
             }
         }
         if (firstColZero) {
             for (i = 0; i < rows; i++) {
                 matrix[i][0] = 0;
             }
         }
     }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{0,0,0,5},
        {4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};

    s.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ",";
        }
        cout << "]" << endl;
    }
}

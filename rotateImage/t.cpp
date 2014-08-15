/*
   You are given an n x n 2D matrix representing an image.
   Rotate the image by 90 degrees (clockwise).

   Follow up:
   Could you do this in-place?
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     void rotate(vector<vector<int> > &matrix) {
         int n = matrix.size();
         if (n < 2) return;

         // rotate from outer side to inner side
         for (int i = 0; i < n/2; i++) {
             for (int j = 0; j < n-2*i-1; j++) {
                 int start = matrix[i][i+j];
                 matrix[i][i+j] = matrix[n-i-1-j][i];
                 matrix[n-i-1-j][i] = matrix[n-i-1][n-i-1-j];
                 matrix[n-i-1][n-i-1-j] = matrix[i+j][n-i-1];
                 matrix[i+j][n-i-1] = start;
             }
         }
     }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;

    matrix = {{1}};
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{1, 2}, {3, 4}};
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
}

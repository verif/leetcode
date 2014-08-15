/*
   Given a matrix of m x n elements (m rows, n columns), return all elements of
   the matrix in spiral order.

   For example,
   Given the following matrix:
   [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
   ]
You should return [1,2,3,6,9,8,7,4,5]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     vector<int> spiralOrder(vector<vector<int> > &matrix) {
         vector<int> empty;
         if (!matrix.size()) return empty;

         int m = matrix.size();
         int n = matrix[0].size();
         int min = m > n ? n : m;
         vector<int> ret;

         int i;
         for (i = 0; i < (min+1)/2; i++) {
             // iterate the peripheral of the current square
             int j;
             for (j = i; j < n-i; j++) {
                 ret.push_back(matrix[i][j]);
             }
             for (j = i+1; j < m-i; j++) {
                 ret.push_back(matrix[j][n-i-1]);
             }
             if (m-i-1 > i) {
                 for (j = n-i-2; j >= i; j--) {
                     ret.push_back(matrix[m-i-1][j]);
                 }
             }
             if (n-i-1 > i) {
                 for (j = m-i-2; j > i; j--) {
                     ret.push_back(matrix[j][i]);
                 }
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> ret;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    ret =s.spiralOrder(matrix);
    for (int i = 0; i < ret.size(); i++) {
	cout << ret[i] << ",";
    }
    cout << endl;

    matrix = {{1,2,3}};
    ret =s.spiralOrder(matrix);
    for (int i = 0; i < ret.size(); i++) {
	cout << ret[i] << ",";
    }
    cout << endl;

    matrix = {{1},{2},{3}};
    ret =s.spiralOrder(matrix);
    for (int i = 0; i < ret.size(); i++) {
	cout << ret[i] << ",";
    }
    cout << endl;

    matrix = {{1}};
    ret =s.spiralOrder(matrix);
    for (int i = 0; i < ret.size(); i++) {
	cout << ret[i] << ",";
    }
    cout << endl;

    matrix = {{1,2},{4,5},{7,8}};
    ret =s.spiralOrder(matrix);
    for (int i = 0; i < ret.size(); i++) {
	cout << ret[i] << ",";
    }
    cout << endl;
}

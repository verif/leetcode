/*
   Given an integer n, generate a square matrix filled with elements from 1 to
   n2 in spiral order.

   For example,
   Given n = 3,
   You should return the following matrix:
   [
    [ 1, 2, 3 ],
    [ 8, 9, 4 ],
    [ 7, 6, 5 ]
   ]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> empty;
         if (!n) return empty;

         vector<vector<int>> ret(n, vector<int>(n));

         int i;
         int start = 1;
         for (i = 0; i < (n+1)/2; i++) {
             // fill out the peripheral of the current square
             int j;
             for (j = i; j < n-i; j++) {
                 ret[i][j] = start++;
             }
             for (j = i+1; j < n-i; j++) {
                 ret[j][n-i-1] = start++;
             }
             for (j = n-i-2; j >= i; j--) {
                 ret[n-i-1][j] = start++;
             }
             for (j = n-i-2; j > i; j--) {
                 ret[j][i] = start++;
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<vector<int>> ret;

    ret = s.generateMatrix(6);

    for (int i = 0; i < ret.size(); i++) {
        cout << "[";
        for (int j = 0; j < ret[0].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << "]" << endl;
    }
}


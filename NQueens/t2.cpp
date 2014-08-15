/*
   Follow up for N-Queens problem.

   Now, instead outputting board configurations, return the total number of
   distinct solutions.
*/

#include <vector>
#include <algorithm> // for 'abs'
#include <iostream>
using namespace std;

class Solution {
public:
     void placeQueen(int rows, vector<int> A, int n, int& total){
         if (rows == n) {
	     total++;
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
                 placeQueen(rows+1, A, n, total);
             }
         }
     }
     int totalNQueens(int n) {
         int ret = 0;
         vector<int> A(n);

         placeQueen(0, A, n, ret);

         return ret;
     }
};
int main()
{
    Solution s;
    int ret;

    ret = s.totalNQueens(8);

    cout << ret << endl;
}

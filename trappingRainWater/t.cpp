/*
   Given n non-negative integers representing an elevation map where the width
   of each bar is 1, compute how much water it is able to trap after raining.

   For example, 
   Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <iostream>
#include <algorithm> // for 'min'
using namespace std;

class Solution {
public:
     int trap(int A[], int n) {
         if (n < 3) return 0;
         int ret = 0;
         int maxRain[n];

         int curMax = A[0];
         for (int i = 0; i < n; i++) {
             if (A[i] < curMax) {
                 maxRain[i] = curMax-A[i];
             }
             else {
                 curMax = A[i];
                 maxRain[i] = 0;
             }
         }

         curMax = A[n-1];
         for (int i = n-1; i >= 0; i--) {
             if (A[i] < curMax) {
                 maxRain[i] = min(curMax-A[i], maxRain[i]);
             }
             else {
                 curMax = A[i];
                 maxRain[i] = 0;
             }
             ret += maxRain[i];
         }

         return ret;
     }
};

int main()
{
    Solution s;
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ret;

    ret = s.trap(A, 12);
    cout << ret << endl;
}

/*
   Find the contiguous subarray within an array (containing at least one
   number) which has the largest sum.

   For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
   the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:

If you have figured out the O(n) solution, try coding another solution using
the divide and conquer approach, which is more subtle.
*/

#include <iostream>
using namespace std;

class Solution {
public:
     int maxSubArray(int A[], int n) {
         int curSum = A[0];
         int maxSum = A[0];

         for (int i = 1; i < n; i++) {
             if (curSum < 0) {
                 curSum = A[i];
             }
             else {
                 curSum += A[i];
             }
             maxSum = maxSum > curSum ? maxSum : curSum;
         }

         return maxSum;
     }
};

int main()
{
    Solution s;
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int ret;

    ret = s.maxSubArray(A, 9);
    cout << ret << endl;
}

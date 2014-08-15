/*
   Given an array of non-negative integers, you are initially positioned at the
   first index of the array.
   Each element in the array represents your maximum jump length at that
   position.
   Your goal is to reach the last index in the minimum number of jumps.

   For example:
   Given array A = [2,3,1,1,4]
   The minimum number of jumps to reach the last index is 2. (Jump 1 step from
   index 0 to 1, then 3 steps to the last index.)
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
     int jump(int A[], int n) {
         if (n < 2) return 0;
         int i = 0;
         int next = 0;
         int njump = 0;

         while (i < n) {
             next = max(next, i+A[i]);
             njump++;
             if (next >= n-1) return njump;
             int tmp = next;
             for (int j = i; j < tmp; j++) {
                 next = max(next, j+A[j]);
             }
             i = tmp;
         }

         return njump;
     }
};

int main()
{
    Solution s;
    int ret;
    int A[] = {2,3,1,1,4};

    ret = s.jump(A, 5);
    cout << ret << endl;
}

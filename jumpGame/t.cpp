/*
   Given an array of non-negative integers, you are initially positioned at the
   first index of the array.
   Each element in the array represents your maximum jump length at that
   position.

   Determine if you are able to reach the last index.
   For example:
   A = [2,3,1,1,4], return true.
   A = [3,2,1,0,4], return false.
*/

#include <iostream>
using namespace std;

// a simple dynamic solution should solve it
class Solution {
public:
     bool canJump(int A[], int n) {
         if (n < 2) return true;

         int nearestIndex = n-1;
         for (int i = n-2; i >= 0; i--) {
             if (A[i] + i >= nearestIndex) nearestIndex = i;
         }

         return !nearestIndex;
     }
};

int main()
{
    Solution s;
    int A[] = {3,2,1,0,4};
    // int A[] = {2,3,1,1,4};
    bool ret;

    ret = s.canJump(A, 5);
    cout << ret << endl;
}


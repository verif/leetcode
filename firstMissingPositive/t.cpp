/*
   Given an unsorted integer array, find the first missing positive integer.

   For example,
   Given [1,2,0] return 3,
   and [3,4,-1,1] return 2.
   Your algorithm should run in O(n) time and uses constant space.
*/

#include <iostream>
#include <algorithm> // for 'swap'
using namespace std;

class Solution {
public:
     int firstMissingPositive(int A[], int n) {
         if (!n) return 1;

         // scan array and put 'i' in A[i-1], ignore those < 1 or > n;
         int i = 0;
         while (i < n) {
             if (A[i] < 1 || A[i] > n) {
                 i++;
                 continue;
             }
             if (A[i] != (i+1) && A[i] != A[A[i]-1]) {
                 swap(A[i], A[A[i]-1]);
             }
             else i++;
         }
         // scan from beginning to get answer
         for (i = 0; i < n; i++) {
             if (A[i] != i+1) return i+1;
         }

         return n+1;
     }
};

int main()
{
    Solution s;
    int A[] = {3,4,-1,1};
    int ret;

    ret = s.firstMissingPositive(A, 4);
    cout << ret << endl;
}

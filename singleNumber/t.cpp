/*
   Given an array of integers, every element appears three times except for
   one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it
without using extra memory?
*/

#include <iostream>
#include <assert.h>
using namespace std;


class Solution {
#define N 3 // number of times every element appears except for one
public:
     int singleNumber(int A[], int n) {
         int i, j;
         int one = 0; // each bit records if there is one '1' for this bit

         for (i = 0; i < 32; i++) { // 32 bits of an integer
             char numOnes = 0; // number of '1's in digit 'i'
             for (j = 0; j < n; j++) { // n elements of A
                 if ((A[j] >> i) & 1) { // 'i'th bit is 1
                     numOnes++;
                     if (numOnes == N) numOnes = 0;
                 }
             }
             if (numOnes == 1) {
                 one = (1 << i) + one;
             }
         }

         return one;
     }

};

int main()
{
    Solution s;
    int ret;

    int A[7] = {1333, 3331, 1333, 1333, -132, -132, -132};

    ret = s.singleNumber(A, 7);
    cout << ret << endl;
}

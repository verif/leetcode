/*
   Find the maximum sum of a sub-sequence from an positive integer array where
   any two numbers of sub-sequence are not adjacent to each other in the
   original sequence. E.g 1 2 3 4 5 6 > 2 4 6

   A = [1,51,3,1,100,199,3], maxSum = 51 + 1 + 199 = 251.
   A = [9, 10, 9], maxSum = 9 + 9
*/

#include <vector>
#include <algorithm> // for 'max'
#include <iostream>
#include <assert.h>

using namespace std;

class MaxSum {
public:
    int maxSumSubsequence(int A[], int len) {
        if (len == 0)
            return 0;
        int S[len+1];
        S[0] = 0;
        S[1] = A[0];
        for (int i = 1; i < len; i++) {
           S[i+1] = std::max(S[i], (S[i-1] + A[i]));
        }
        return S[len];
    }
};

int main() {
    MaxSum ms;

    int A1[]  = {1, 2, 3, 4, 5, 6};
    int ret;

    ret = ms.maxSumSubsequence(A1, 6);
    cout << ret << endl;
    assert(ret == 12);

    int A2[] = {1,51,3,1,100,199,3};
    ret = ms.maxSumSubsequence(A2, 7);
    cout << ret << endl;
    assert(ret == (51 + 1 + 199));

    int A3[] = {9,10,9};
    ret = ms.maxSumSubsequence(A3, 3);
    cout << ret << endl;
    assert(ret == 18);

    int A4[] = {9,100,9};
    ret = ms.maxSumSubsequence(A4, 3);
    cout << ret << endl;
    assert(ret == 100);
}

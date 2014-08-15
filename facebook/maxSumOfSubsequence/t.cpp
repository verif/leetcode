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

using namespace std;

class MaxSum {
public:
    int maxSumSubsequence(int A[], int len) {
        if (!len) return 0;
        int p[len+1];

        p[len] = 0; p[len-1] = A[len-1];
        for (int i = len-2; i >= 0; i--) {
            p[i] = std::max(p[i+1], A[i]+p[i+2]);
        }

        return p[0];
    }
};

int main() {
    MaxSum ms;

    int A1[]  = {1, 2, 3, 4, 5, 6};
    int ret;

    ret = ms.maxSumSubsequence(A1, 6);
    cout << ret << endl;

    int A2[] = {1,51,3,1,100,199,3};
    ret = ms.maxSumSubsequence(A2, 7);
    cout << ret << endl;

    int A3[] = {9,10,9};
    ret = ms.maxSumSubsequence(A3, 3);
    cout << ret << endl;
}

/*
   Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n)
to hold additional elements from B. The number of elements initialized in A and
B are m and n respectively.
*/

#include <iostream>
using namespace std;

// Merge from end to beginning
class Solution {
public:
     void merge(int A[], int m, int B[], int n) {
         if (n <= 0) return;
         int ai = m-1;
         int bi = n-1;
         int idx = m+n-1;

         while (ai >= 0 && bi >= 0) {
             if (A[ai] > B[bi]) {
                 A[idx] = A[ai];
                 ai--;
             }
             else {
                 A[idx] = B[bi];
                 bi--;
             }
             idx--;
         }

         if (ai < 0) {
             while (bi >= 0) {
                 A[bi] = B[bi];
                 bi--;
             }
         }
     }
};

int main()
{
    Solution s;
    int A[10] = {1,3,5,7,9,0,0,0,0,0};
    int B[5] = {2,4,6,8,10};

    s.merge(A, 5, B, 5);

    for (int i = 0; i < 10; i++) {
        cout << A[i] << ",";
    }
    cout << endl;

    int A1[1];
    int B1[1] = {1};

    s.merge(A1, 0, B1, 1);

    for (int i = 0; i < 1; i++) {
        cout << A[i] << ",";
    }
    cout << endl;
}

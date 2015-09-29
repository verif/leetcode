/*
   There are two sorted arrays A and B of size m and n respectively. Find the
   median of the two sorted arrays. The overall run time complexity should be
   O(log (m+n)).
*/

#include <iostream>
using namespace std;

class Solution {
public:
     // Find idx'th element from A/B - idx starts from 0
    int findKthElem(int A[], int M, int B[], int N, int idx) {
         if (M <= 0) return B[idx];
         if (N <= 0) return A[idx];
         if (!idx) return min(A[0], B[0]);
         if (M > N) return findKthElem(B, N, A, M, idx);
         
         int aNum = min((idx+1)/2, M);
         int bNum = idx - aNum + 1;
         if (!aNum)
             return B[idx];
         if (!bNum)
             return A[idx];
         if (A[aNum-1] == B[bNum-1]) {
             return A[aNum-1];
         }
         else if (A[aNum-1] > B[bNum-1]) {
             // drop B[0] .. B[bNum-1]
             return findKthElem(A, M, &B[bNum], N - bNum, idx - bNum); 
         }
         else {
             // drop A[0] .. A[aNum-1]
             return findKthElem(&A[aNum], M - aNum, B, N, idx - aNum);
         }
     }

     double findMedianSortedArrays(int A[], int m, int B[], int n) {
         if (!m) return getMedianOneArray(B, n);
         if (!n) return getMedianOneArray(A, m);
         if ((m+n)%2) {
             return findKthElem(A, m, B, n, (m+n)/2);
         }
         else {
             return (findKthElem(A, m, B, n, (m+n)/2)+
                     findKthElem(A, m, B, n, (m+n)/2-1)) / 2.0;
         }
     }

     double getMedianOneArray(int A[], int m) {
         if (m%2)
             return A[m/2];
         else
             return (A[m/2] + A[m/2 - 1]) / 2.0;
     }

     double findMedianDumbWay(int A[], int m, int B[], int n) {
         double val;
         int is_odd_num = ((m+n)%2);
         int k;

         if (is_odd_num) {
             k = (m+n)/2;
         }
         else {
             k = (m+n)/2 - 1;
         }

         // iterate from beginning of A/B until we reach kth element
         int ai = 0;
         int bi = 0;
         for (int cnt = 0; cnt <= k; cnt++) {
             if (A[ai] < B[bi]) {
                 val = A[ai];
                 ai++;
             }
             else {
                 val = B[bi];
                 bi++;
             }
         }
         if (!is_odd_num) {
             // advance to next item
             if (A[ai] < B[bi])
                 val += A[ai];
             else
                 val += A[ai];
             val = val / 2.0;
         }
         return val;
     }
};

int main()
{
    Solution s;
    double ret;
    double exp;
    string test;

    int A[] = {1, 3, 5, 7, 9, 13};
    int B[] = {2, 4, 6, 8, 10};
    int M = sizeof(A)/sizeof(A[0]);
    int N = sizeof(B)/sizeof(B[0]);

    ret = s.findMedianSortedArrays(A, M, B, N);
    exp = s.findMedianDumbWay(A, M, B, N);

    for (int i = 0; i < (M+N); i++)
      cout << s.findKthElem(A, M, B, N, i) << endl;

    test = getcwd(NULL, 0);
    test = test.substr(test.rfind("/") + 1, string::npos);
    if (ret != exp)
      cout << "Testcase " << test << " FAILED expect: " << exp << " actual: " << ret << endl;
    else
      cout << "Testcase " << test << " PASSED" << endl;
}


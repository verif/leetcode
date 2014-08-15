/*
   There are two sorted arrays A and B of size m and n respectively. Find the
   median of the two sorted arrays. The overall run time complexity should be
   O(log (m+n)).
*/

#include <iostream>

class Solution {
public:
     // Find k'th element from A/B - idx starts from 0
     double findKthElem(int A[], int m, int B[], int n, int k) {
         if (m>n) return findKthElem(B, n, A, m, k);
         if (!m) return B[k];
         if (k == 0) return std::min(A[0], B[0]);
         int pa = std::min((k+1)/2, m);
         int pb = k+1-pa;
         if (A[pa-1] > B[pb-1]) return findKthElem(A, pa, B+pb, n-pb, k-pb);
         else return findKthElem(A+pa, m-pa, B, pb, k-pa);
     }
     double findMedianSortedArrays(int A[], int m, int B[], int n) {
         if (!m) return (B[n/2]+B[(n-1)/2])/2.0;
         if (!n) return (A[m/2]+A[(m-1)/2])/2.0;
         if ((m+n)%2) {
             return findKthElem(A, m, B, n, (m+n)/2);
         }
         else {
             return (findKthElem(A, m, B, n, (m+n)/2)+
                     findKthElem(A, m, B, n, (m+n)/2-1)) / 2;
         }
     }
};

int main()
{
    Solution s;

    double ret;

    int A[] = {1, 2, 5, 7, 9};
    int B[] = {1, 2, 6, 8, 10};

    ret = s.findMedianSortedArrays(A, 2, B, 2);
    std::cout << ret << std::endl;
}


/*
   There are two sorted arrays A and B of size m and n respectively. Find the
   median of the two sorted arrays. The overall run time complexity should be
   O(log (m+n)).
*/

#include <iostream>

class Solution {
public:
     
     // Find idx'th element from A/B - idx starts from 0
     int findKthElem(int A[], int as, int ae, int B[], int bs, int be, 
                        int idx) {
         if ((ae-as) > (be-bs)) return findKthElem(B, bs, be, A, as, ae, idx);

         if (!idx) return A[as] < B[bs] ? A[as] : B[bs]; 
         if (as == ae) {
             if (be-bs == idx-1) {
                 return A[as] > B[be] ? A[as] : B[be];
             }
             return A[as] > B[bs+idx] ? B[bs+idx] : A[as] > B[bs+idx-1] ? A[as] : B[bs+idx-1];
         }
         
         
         int newIdx = (ae-as) > idx/2 ? idx/2 : ae-as;
         if (A[newIdx+as] > B[idx-newIdx+bs]) {
             return findKthElem(A, as, as+newIdx-1, B, idx-newIdx+bs, be,
                                newIdx); 
         }
         else {
             return findKthElem(A, as+newIdx, ae, B, bs, bs+idx-newIdx-1,
                                idx-newIdx); 
         }
     }
     double findMedianSortedArrays(int A[], int m, int B[], int n) {
         if (!m) return (B[n/2]+B[(n-1)/2])/2.0;
         if (!n) return (A[m/2]+A[(m-1)/2])/2.0;
         if ((m+n)%2) {
             return findKthElem(A, 0, m-1, B, 0, n-1, (m+n)/2);
         }
         else {
             return (findKthElem(A, 0, m-1, B, 0, n-1, (m+n)/2)+
                     findKthElem(A, 0, m-1, B, 0, n-1, (m+n)/2-1)) / 2.0;
         }
     }
};

int main()
{
    Solution s;

    double ret;

    int A[] = {1, 3, 5, 7, 9};
    int B[] = {1, 4, 6, 8, 10};

    ret = s.findMedianSortedArrays(A, 1, B, 1);
    std::cout << ret << std::endl;
}


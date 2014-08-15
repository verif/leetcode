/*
   Suppose a sorted array is rotated at some pivot unknown to you beforehand.
   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

   Follow up for "Search in Rotated Sorted Array":
   What if duplicates are allowed?
   Would this affect the run-time complexity? How and why?
   Write a function to determine if a given target is in the array.
*/

#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
     bool searchNoPivot(int A[], int n, int begin, int end, int target)
     {
         bool ret = false;
         assert(n>=0);
         if (!n) return false;
         if (n == 1) {
             ret = (A[begin] == target) ? true : false;
             return ret;
         }

         if (target < A[begin] || target > A[end]) return false;

         int mid = (begin+end)/2;
         if (target > A[mid]) {
             return searchNoPivot(A, end-mid, mid+1, end, target);
         }
         else {
             return searchNoPivot(A, mid-begin+1, begin, mid, target);
         }
     }

     bool searchPivot(int A[], int n, int begin, int end, int target)
     {
         bool ret = false;
         assert(n>=0);
         if (!n) return false;
         if (n == 1) {
             ret = (A[begin] == target) ? true : false;
             return ret;
         }
         assert(end >= begin);
         int mid = (begin+end)/2;
         if (A[begin] < A[mid] || A[mid+1] > A[end]) { // pivot in 2nd half
             if (A[begin] <= target && A[mid] >= target) {
                 return searchNoPivot(A, mid-begin+1, begin, mid, target);
             }
             else {
                 return searchPivot(A, end-mid, mid+1, end, target);
             }
         } 
         else if (A[mid+1] < A[end] || A[begin] > A[mid]) { // pivot in 1st half
             if (A[mid+1] <= target && A[end] >= target) {
                 return searchNoPivot(A, end-mid, mid+1, end, target);
             }
             else {
                 return searchPivot(A, mid-begin+1, begin, mid, target);
             }
         }
         else {
             assert(A[begin] == A[mid]);
             assert(A[mid+1] == A[end]);
             int idx1 = searchPivot(A, mid-begin+1, begin, mid, target);
             if (idx1) return idx1;
             bool idx2 = searchPivot(A, end-mid, mid+1, end, target);
             return idx2;
         }
     }

     bool search(int A[], int n, int target) {
         return searchPivot(A, n, 0, n-1, target);
     }
};

int main()
{
    Solution s;
    int A[] = {1};

    int idx = s.search(A, 1, 1);
    cout << idx << endl;
}


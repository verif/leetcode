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
     bool searchPivot(int A[], int start, int end, int target) {
         int mid = start + (end-start)/2;
         if (end < start) return false;
         if (target == A[mid]) return true;

         if (A[mid] > A[start]) {
             if (target >= A[start] && target <= A[mid]) {
                 return searchPivot(A, start, mid, target);
             }
             else {
                 return searchPivot(A, mid+1, end, target);
             }
         }
         else if (A[mid] < A[start]) {
             if (target >= A[mid] && target <= A[end]) {
                 return searchPivot(A, mid, end, target);
             }
             else {
                 return searchPivot(A, start, mid-1, target);
             }
         }
         else {
             return searchPivot(A, start+1, end, target);
         }
     }
     bool search(int A[], int n, int target) {
         return searchPivot(A, 0, n-1, target);
     }
};

int main()
{
    Solution s;
    int A[] = {1};
    //int A[] = {4, 5, 6, 7, 0, 1, 2};

    int idx = s.search(A, 1, 0);
    cout << idx << endl;
}


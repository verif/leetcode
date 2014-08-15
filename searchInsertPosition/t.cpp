/*
   Given a sorted array and a target value, return the index if the target is
   found. If not, return the index where it would be if it were inserted in
   order.

   You may assume no duplicates in the array.

   Here are few examples.

   [1,3,5,6], 5 -> 2 
   [1,3,5,6], 2 -> 1
   [1,3,5,6], 7 -> 4
   [1,3,5,6], 0 -> 0
*/

#include <iostream>
using namespace std;

class Solution {
public:
     int searchInsertRecur(int A[], int start, int end, int target)
     {
         if (A[start] >= target) return start;
         if (A[end] < target) return end+1;
         if (start >= end) {
             return A[end] < target ? end+1 : end;
         }
         int mid = (start+end)/2;
         if (A[mid] > target) {
             return searchInsertRecur(A, start, mid-1, target);
         }
         else if (A[mid] < target) {
             return searchInsertRecur(A, mid+1, end, target);
         }
         else return mid;
     }
     int searchInsert(int A[], int n, int target) {
         if (!n) return 0;
         return searchInsertRecur(A, 0, n-1, target);
     }
};

int main()
{
    Solution s;
    int ret;
    int A[] = {1,3,5,6};

    ret = s.searchInsert(A, 4, 5);
    cout << "5 => " << ret << endl;

    ret = s.searchInsert(A, 4, 2);
    cout << "2 => " << ret << endl;

    ret = s.searchInsert(A, 4, 7);
    cout << "7 => " << ret << endl;

    ret = s.searchInsert(A, 4, 0);
    cout << "0 => " << ret << endl;

    ret = s.searchInsert(A, 4, 4);
    cout << "4 => " << ret << endl;
}

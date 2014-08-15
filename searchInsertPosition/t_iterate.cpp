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
     int searchInsert(int A[], int n, int target) {
         if (!n) return 0;
         int start = 0;
         int end = n;
         int mid = n/2;

         while (start < end) {
             if (A[mid] > target) {
                 end = mid-1;
             }
             else if (A[mid] < target) {
                 start = mid+1;
             }
             else {
                 return mid;
             }
             mid = (start+end)/2;
         }

         if (end < 0) return 0;
         if (start >= n) return n;

         return A[end] < target ? end+1 : end;
     }
};

int main()
{
    Solution s;
    int ret;
    int A[] = {1,3, 4, 5,6};

    ret = s.searchInsert(A, 5, 5);
    cout << "5 => " << ret << endl;

    ret = s.searchInsert(A, 5, 2);
    cout << "2 => " << ret << endl;

    ret = s.searchInsert(A, 5, 7);
    cout << "7 => " << ret << endl;

    ret = s.searchInsert(A, 5, 0);
    cout << "0 => " << ret << endl;

    ret = s.searchInsert(A, 5, 4);
    cout << "4 => " << ret << endl;
}

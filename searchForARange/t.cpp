/*
   Given a sorted array of integers, find the starting and ending position of a
   given target value.
   Your algorithm's runtime complexity must be in the order of O(log n).
   If the target is not found in the array, return [-1, -1].

   For example,
   Given [5, 7, 7, 8, 8, 10] and target value 8,
   return [3, 4].
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     vector<int> searchRange(int A[], int n, int target) {
         vector<int> ret = {-1, -1};
         if (!n) return ret;

         int start = 0;
         int end = n-1;
         int mid = (start+end)/2;

         while (start < end) {
             if (A[mid] > target) {
                 end = mid-1;
             }
             else if (A[mid] < target) {
                 start = mid+1;
             }
             else {
                 break;
             }
             mid = (start+end)/2;
         }
         if (A[mid] != target) return ret;

         start = end = mid;
         while (start >= 0 && A[start] == target) start--;
         while (end < n && A[end] == target) end++;
         ret[0] = start >= 0 ? start+1 : 0;
         ret[1] = end < n ? end-1 : n-1;

         return ret;
     }
};

int main()
{
    Solution s;
    int A[] = {5,7,7,8,8,10};
    vector<int> ret;

    ret = s.searchRange(A, 6, 8);
    cout << "start: " << ret[0] << ", end: " << ret[1] << endl;
}

/*
   Given a sorted array, remove the duplicates in place such that each element
   appear only once and return the new length.

   Do not allocate extra space for another array, you must do this in place
   with constant memory.
   For example,
   Given input array A = [1,1,2],
   Your function should return length = 2, and A is now [1,2].
*/

#include <iostream>

class Solution {
public:
     int removeDuplicates(int A[], int n) {
         if (!n) return 0;
         int i = 0;
         int j = 0;
         while (j < n) {
             A[i] = A[j];
             i++; j++;
             while (j < n && A[j] == A[j-1]) j++;
         }
         return i;
     }
};

int main()
{
    Solution s;
    int A[] = {1, 1, 2};
    int ret;

    ret = s.removeDuplicates(A, 3);
    for (int i = 0; i < ret; i++) {
        std::cout << A[i] << ",";
    }
    std::cout << std::endl;
}

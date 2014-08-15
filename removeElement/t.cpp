/*
   Given an array and a value, remove all instances of that value in place and
   return the new length.

   The order of elements can be changed. It doesn't matter what you leave
   beyond the new length.
*/

#include <iostream>

class Solution {
public:
     int removeElement(int A[], int n, int elem) {
         if (!n) return 0;
         int i = 0; 
         int j = n-1;

         while (i <= j) {
             if (A[i] == elem) {
                 while (j >= 0 && A[j] == elem) j--;
                 if (j < 0 || i > j) break;
                 A[i] = A[j];
                 j--;
             }
             i++;
         }

         return j+1;
     }
};

int main()
{
    Solution s;
    int A[] = {2,2,2,1,1};
    int ret;

    ret = s.removeElement(A, 5, 1);
    std::cout << ret << std::endl;
}

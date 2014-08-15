/*
   Given an array with n objects colored red, white or blue, sort them so that
   objects of the same color are adjacent, with the colors in the order red,
   white and blue.

   Here, we will use the integers 0, 1, and 2 to represent the color red,
   white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

#include <iostream>
#include <assert.h>
#include <algorithm> // for std::swap
using namespace std;

class Solution {
public:
     void sortColors(int A[], int n) {
         if (n < 2) return;
         int i1 = 0;
         int i2 = n-1;
         int i = i1;
         while (i <= i2) {
             if (A[i] == 0) {
                 if (i > i1) swap(A[i], A[i1]);
                 i1++;
                 i = i < i1 ? i1 : i;
             }
             else if (A[i] == 2) {
                 if (i < i2) swap(A[i], A[i2]);
                 i2--;
             }
             else {
                 i++;
             }
         }
     }
};

int main()
{
    Solution s;
    int A[] = {1,0, 0, 1, 2, 1, 0, 2, 2, 2};

    s.sortColors(A, 10);

    for (int i = 0; i < 10; i++) {
        cout << A[i] << ",";
    } 
    cout << endl;
}


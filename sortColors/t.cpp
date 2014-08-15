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
using namespace std;

class Solution {
public:
     void sortColors(int A[], int n) {
         if (n < 2) return;
         int i1 = 0;
         int i2 = n-1;
         int i;
         int blueCnt = 0;
         int redCnt = 0;
         while (i1 < i2 && A[i1] == 0) i1++;
         while (i1 < i2 && A[i2] == 2) i2--;

         if (i1 == i2) return;
         for (i = i1; i <= i2; i++) {
             if (A[i] == 0) {
                 assert(A[i1]);
                 if (A[i1] == 2) blueCnt++;
                 A[i1] = 0;
                 A[i] = 1;
                 while (i1 < i2 && A[i1] == 0) i1++;
                 i = i < i1 ? i1-1 : i;
             }
             else if (A[i] == 2) {
                 assert(A[i2] < 2);
                 if (A[i2] == 0) redCnt++;
                 A[i2] = 2;
                 A[i] = 1;
                 while (i1 < i2 && A[i2] == 2) i2--;
             }
             else {
                 assert(A[i] == 1);
             }
         }

         while (redCnt) {
             assert(A[i1]);
             A[i1] = 0;
             i1++;
             redCnt--;
         }

         while (blueCnt) {
             assert(A[i2] < 2);
             A[i2] = 2;
             i2--;
             blueCnt--;
         }

         for (i = i1; i <= i2; i++) {
             A[i] = 1;
         }
     }
};

int main()
{
    Solution s;
    int A[] = {0,0, 0, 1, 2, 1, 0, 2, 2, 2};

    s.sortColors(A, 2);

    for (int i = 0; i < 10; i++) {
        cout << A[i] << ",";
    } 
    cout << endl;
}


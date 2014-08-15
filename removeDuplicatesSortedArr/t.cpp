/*
   Follow up for "Remove Duplicates":
   What if duplicates are allowed at most twice?

   For example,
   Given sorted array A = [1,1,1,2,2,3],
   Your function should return length = 5, and A is now [1,1,2,2,3].
*/

#include <iostream>
using namespace std;

class Solution {
public:
     int removeDuplicates(int A[], int n) {
         if (n < 3) return n;
         int ret = n;
         int idx = 0;
         int i = 0;

         while (i < n) {
             int cnt = 0;
             int j;
             for (j = i; j < n; j++) {
                 if (A[i] != A[j]) break;
                 if (j != idx) {
                     A[idx] = A[j];
                 }
                 cnt++;
                 if (cnt < 3) idx++;
             }

             if (cnt > 2) ret -= (cnt-2);

             i = j;
         }

         return ret;
     }
};

int main()
{
    Solution s;
    int A[] = {1, 1, 1, 2, 2, 3};
    int ret;

    ret = s.removeDuplicates(A, 6);
    cout << ret << endl;
    for (int i = 0; i < ret; i++) {
        cout << A[i] << ",";
    } 
    cout << endl;
}

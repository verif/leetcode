/*
   The set [1,2,3,..., n] contains a total of n! unique permutations.
   By listing and labeling all of the permutations in order,
   We get the following sequence (ie, for n = 3):
   "123"
   "132"
   "213"
   "231"
   "312"
   "321"
   Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
     string getPermutation(int n, int k) {
         int a[10];
         int taken[10] = {0};
         int i = 0;
         string ret;

         a[0] = 1;
         a[1] = 1;
         for (i = 2; i < 10; i++) {
             a[i] = a[i-1]*i;
         }

         int r = 0;
         for (i = 1; i <= n; i++) {
             r = 1 + (k-1)/a[n-i];
             k = k - ((r-1) * a[n-i]);
             int cnt = 0;
             for (int j = 1; j < 10; j++) {
                 if (!taken[j]) cnt++;
                 if (cnt == r) {
                     ret.push_back('0'+j);
                     taken[j] = 1;
                     break;
                 }
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;
    string ret;

    ret = s.getPermutation(1, 1);
    cout << ret << endl;
}

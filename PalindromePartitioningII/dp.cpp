/*
   Given a string s, partition s such that every substring of the partition is
   a palindrome.
   Return the minimum cuts needed for a palindrome partitioning of s.
   For example, given s = "aab",
   Return 1 since the palindrome partitioning ["aa","b"] could be produced
   using 1 cut.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
     int minCut(string s) {
         int len = s.length();

         if (len < 2) return 0;
         int numCuts[len];
         bool isPal[len][len];

         int i, j;

         for (i = 0; i < len; i++) {
             numCuts[i] = i;
             for (j = 0; j < len; j++) {
                 isPal[i][j] = i >= j ? true : false;
             }
         }

         isPal[0][0] = true;
         for (i = 1; i < len; i++) {
             for (j = i; j >= 0; j--) {
                 if ((i-j<2 || isPal[j+1][i-1]) && s.at(j) == s.at(i)) {
                     isPal[j][i] = true;
                     int curMin = j > 0 ? numCuts[j-1] : -1;
                     numCuts[i] = numCuts[i] > curMin+1 ? curMin+1
                                     : numCuts[i];
                 }
             }
         }
         return numCuts[len-1];
     }
};

int main()
{
    Solution s;
    int ret = s.minCut("abcdefgfedabc");
    cout << "Min cuts: " << ret << endl;
}


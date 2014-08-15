/*
   Given a string S and a string T, count the number of distinct subsequences
   of T in S.
   A subsequence of a string is a new string which is formed from the original
   string by deleting some (can be none) of the characters without disturbing
   the relative positions of the remaining characters. (ie, "ACE" is a
   subsequence of "ABCDE" while "AEC" is not).

   Here is an example:
   S = "rabbbit", T = "rabbit"
   Return 3.
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int numDistinct(string S, string T) {
         int len1 = S.length();
         int len2 = T.length();

         if (!len1 || !len2 || len1 < len2) return 0;

         // P[i][j]: number of distinct subsequences for last j chars from T in
         // last i chars from S
         int P[len1+1][len2+1];

         int i, j;

         for (j = 0; j < len2; j++) {
             P[0][j] = 0;
         }
         for (i = 0; i < len1; i++) {
             P[i][0] = 1;
         }

         for (j = 1; j <= len2; j++) {
             P[j-1][j] = 0;
             for (i = j; i <= len1; i++) {
                 P[i][j] = S.at(len1-i) == T.at(len2-j) ?
                     P[i-1][j-1]+P[i-1][j] : P[i-1][j];
             }
         } 
         
         return P[len1][len2];
     }
};

int main()
{
    Solution s;
    string S = "rabbbit";
    string T = "rabbit";
    int ret;

    ret = s.numDistinct(S, T);
    cout << ret << endl;
}

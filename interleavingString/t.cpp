/*
   Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
   s2.
   For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include <string>
#include <iostream>
using namespace std;

// use some dynamic programming
class Solution {
public:
     bool isInterleave(string s1, string s2, string s3) {
         int len1 = s1.length();
         int len2 = s2.length();
         int len = s3.length();
         if (len != len1 + len2) return false;
         if (!len1) return !s3.compare(s2);
         if (!len2) return !s3.compare(s1);

         bool p[len1+1][len2+1];
         int i, j;

         // Initial condition for DP
         p[0][0] = true;
         
         string sub1, sub2, sub;
         for (i = 1; i <= len1; i++) {
             p[i][0] = p[i-1][0] && s3[len-i] == s1[len1-i];
             for (j = 1; j <= len2; j++) {
                 p[0][j] = p[0][j-1] && s3[len-j] == s2[len2-j];
                 sub1 = s1.substr(len1-i, i);
                 sub2 = s2.substr(len2-j, j);
                 sub = s3.substr(len-i-j, i+j);
                 p[i][j] = false;
                 if (sub1[0] == sub[0] && p[i-1][j]) {
                     p[i][j] = true;
                 }
                 if (sub2[0] == sub[0] && p[i][j-1]) {
                     p[i][j] = true;
                 }
             }
         }

         return p[len1][len2];
     }
};

int main()
{
    Solution s;
    bool ret;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    ret = s.isInterleave(s1, s2, s3);
    cout << ret << endl;

    s3 = "aadbbbaccc";
    ret = s.isInterleave(s1, s2, s3);
    cout << ret << endl;

    s1 = "aabaac";
    s2 = "aadaaeaaf";
    s3 = "aadaaeaabaafaac";
    ret = s.isInterleave(s1, s2, s3);
    cout << ret << endl;

    s1 = "a";
    s2 = "b";
    s3 = "aa";
    ret = s.isInterleave(s1, s2, s3);
    cout << ret << endl;

}

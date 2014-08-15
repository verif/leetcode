/*
   Given a string s1, we may represent it as a binary tree by partitioning it
   to two non-empty substrings recursively.
   Below is one possible representation of s1 = "great":
       great
       /    \
      gr    eat
     / \    /  \
    g   r  e   at
               / \
              a   t

  To scramble the string, we may choose any
  non-leaf node and swap its two children.
  For example, if we choose the node "gr" and
  swap its two children, it produces a
  scrambled string "rgeat".

          rgeat
          /    \
         rg    eat
        / \    /  \
       r   g  e   at
                  / \
                 a   t
 We say that "rgeat" is a scrambled string of "great". 
 Similarly, if we continue to swap the children of
 nodes "eat" and "at", it produces a scrambled string "rgtae".

     rgtae
     /    \
    rg    tae
   / \    /  \
  r   g  ta  e
         / \
        t   a

We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if
s2 is a scrambled string of s1.
*/

#include <iostream>
#include <string>
using namespace std;

// 3-dimension dynamic programming
class Solution {
public:
     bool isScramble(string s1, string s2) {
         if (s1.length() != s2.length()) return false;
         int len = s1.length();
         if (!len) return true;

         bool p[len+1][len][len];
         int i, j, k;

         // initial condition
         for (i = 0; i < len; i++) {
             for (j = 0; j < len; j++) {
                 p[1][i][j] = (s1[i] == s2[j]);
             }
         }

         for (k = 2; k <= len; k++) { // 'k' is length of string being checked
             for (i = len-k; i >= 0; i--) {
                 for (j = len-k; j >= 0; j--) {
                     p[k][i][j] = false;
                     for (int m = 1; m < k; m++) {
                         if (p[m][i][j] && p[k-m][i+m][j+m]) p[k][i][j] = true;
                         if (p[m][i][j+k-m]&&p[k-m][i+m][j]) p[k][i][j] = true;
                     }
                 }
             }
         }

         return p[len][0][0];
     }
};

int main()
{
    Solution s;
    bool ret;
    string s1 = "great";
    string s2 = "rgeat";

    ret = s.isScramble(s1, s2);
    cout << ret << endl;

    s2 = "rgtae";
    ret = s.isScramble(s1, s2);
    cout << ret << endl;

    s2 = "agtre";
    ret = s.isScramble(s1, s2);
    cout << ret << endl;

    string s3 = "abc";
    string s4 = "bca";
    ret = s.isScramble(s3, s4);
    cout << ret << endl;
}

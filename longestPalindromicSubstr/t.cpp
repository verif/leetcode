/*
   Given a string S, find the longest palindromic substring in S. You may
   assume that the maximum length of S is 1000, and there exists one unique
   longest palindromic substring.
*/

#include <string>
#include <iostream>
using namespace std;

// An easy solution is to check each char as the pivot point
class Solution {
public:
     void longestPalindromeAt(string &s, int& start, int &end, int &maxLen,
                             string &res) {
         while (start >= 0 && end < (int)s.length()) {
             if (s[start] != s[end]) break;
             start--;
             end++;
         }
         if (maxLen < end-start-1) {
             maxLen = end-start-1;
             res = s.substr(start+1, end-start-1);
         }
     }
     string longestPalindrome(string s) {
         if (s.length() < 2) return s;
         string ret;
         int i;
         int maxLen = 0;
         for (i = 0; i < (int)s.length(); i++) {
             int start = i-1;
             int end = i+1;

             // check 'i' as sole pivot
             longestPalindromeAt(s, start, end, maxLen, ret);

             // check 'i'/'i+1' as dual pivots
             if (i < (int)s.length()-1 && s[i] == s[i+1]) {
                 start = i-1;
                 end = i+2;
             }
             longestPalindromeAt(s, start, end, maxLen, ret);
         }

         return ret;
     }
};

int main()
{
    Solution s;
    string ret;
    string str = "IIIOOOIII";

    ret = s.longestPalindrome(str);
    cout << ret << endl;
}

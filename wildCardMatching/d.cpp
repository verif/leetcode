/*
   Implement wildcard pattern matching with support for '?' and '*'.
   '?' Matches any single character.
   '*' Matches any sequence of characters (including the empty sequence).

   The matching should cover the entire input string (not partial).
   The function prototype should be:
   bool isMatch(const char *s, const char *p)

   Some examples:
   isMatch("aa","a") -> false
   isMatch("aa","aa") -> true
   isMatch("aaa","aa") -> false
   isMatch("aa", "*") -> true
   isMatch("aa", "a*") -> true
   isMatch("ab", "?*") -> true
   isMatch("aab", "c*a*b") -> false
*/

#include <iostream>
#include <string>
using namespace std;

// try dynamic programm to solve this problem
class Solution {
public:
     bool isMatch(const char *s, const char *p) {
         if (!s || !p) return false;
         if (!*s) return !*p || *p == '*';
         if (!*p) return !*s;

         string str1(s);
         string str2(p);

         int len1 = str1.length();
         int len2 = str2.length();

         bool** dp = new  bool*[len1+1];
         for (int i = 0; i < len1+1; i++) {
             dp[i] = new bool[len2+1];
         }

         // initial condition
         dp[0][0] = 1;
         for (int i = 1; i <= len1; i++) {
            dp[i][0] = 0;
         }
         for (int j = 1; j <= len2; j++) {
            dp[0][j] = dp[0][j-1] && str2[len2-j] == '*';
         }

         for (int i = 1; i <= len1; i++) {
             // string sub1 = str1.substr(len1-i);
             for (int j = 1; j <= len2; j++) {
                // string sub2 = str2.substr(len2-j);
                 char c = str2[len2-j];
                 dp[i][j] = 0;
                 if (c == '*') {
                     for (int k = i; k>=0; k--) {
                         if (dp[k][j-1]) {
                             dp[i][j] = 1;
                             break;
                         }
                     }
                 }
                 else if (c == '?') {
                     dp[i][j] = dp[i-1][j-1];
                 }
                 else {
                     dp[i][j] = (c==str1[len1-i]) && dp[i-1][j-1];
                 }
                 // cout << sub1 << "," << sub2 << ": " << dp[i][j] << endl;
             }
         }

         return dp[len1][len2];
     }
};

int main()
{
    Solution s;

    cout << "aa, a is " << s.isMatch("aa", "a") << endl;
    cout << "aa, aa is " << s.isMatch("aa", "aa") << endl;
    cout << "aaa, aa is " << s.isMatch("aaa", "aa") << endl;
    cout << "aa, * is " << s.isMatch("aa", "*") << endl;
    cout << "aa, a* is " << s.isMatch("aa", "a*") << endl;
    cout << "ab, ?* is " << s.isMatch("ab", "?*") << endl;
    cout << "aab, c*a*b is " << s.isMatch("aab", "c*a*b") << endl;
    cout << "aab, *a*b is " << s.isMatch("aab", "*a*b") << endl;
    cout << "aab, *a??*b is " << s.isMatch("aab", "*a??*b") << endl;
    cout << "b, **? is " << s.isMatch("b", "**?") << endl;
    cout << "b, **?? is " << s.isMatch("b", "**??") << endl;
    cout <<
        "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb, **aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb is " << s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb") << endl;

    string s1, s2;
    for (int i = 0; i < 16248; i++) {
        s1.push_back('a');
        s2.push_back('a');
    }
    s2.push_back('*');
    cout << s.isMatch(s1.c_str(), s2.c_str()) << endl;
}

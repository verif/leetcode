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
using namespace std;

class Solution {
public:
     bool isMatch(const char *s, const char *p) {
         if (!p || !s) return false;

         bool starFound = false;
         const char *ps = NULL;
         const char *ss = NULL;
         while (*s) {
             if (*p == '?' || *p == *s) {p++; s++; continue;}
             if (*p == '*') {
                 starFound = true;
                 ps = p++;
                 ss = s;
                 continue;
             }
             if (starFound) {
                 p = ps+1;
                 s = ++ss;
                 continue;
             }
             return false;
         }
         while (*p == '*') p++;
         return !*p;
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

/*
   Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "a*") -> true
isMatch("aa", ".*") -> true
isMatch("ab", ".*") -> true
isMatch("aab", "c*a*b") -> true
*/

#include <iostream>

class Solution {
public:
     bool isMatch(const char *s, const char *p) {
         if (!s || !p) return false;
         if (!*p) return !*s;
         
         if (*(p+1) == '*') {
             while (*p == *s || (*p == '.' && *s)) {
                 if (isMatch(s, p+2)) return true;
                 s++;
             }
             return isMatch(s, p+2);
         }
         else {
             if (*s == *p || (*p == '.' && *s)) {
                 return isMatch(s+1, p+1);
             }
             else {
                 return false;
             }
         }
     }
};

int main() {
    Solution s;
    std::cout << "\"\", . " << s.isMatch("",".") << std::endl;
    std::cout << "a, ab* " << s.isMatch("a","ab*") << std::endl;
    std::cout << "aa, a " << s.isMatch("aa","a") << std::endl;
    std::cout << "aa, aa " << s.isMatch("aa","aa") << std::endl;
    std::cout << "aaa, aa " << s.isMatch("aaa","aa") << std::endl;
    std::cout << "aa, a* " << s.isMatch("aa","a*") << std::endl;
    std::cout << "aa, .* " << s.isMatch("aa",".*") << std::endl;
    std::cout << "ab, .* " << s.isMatch("ab",".*") << std::endl;
    std::cout << "aab, c*a*b " << s.isMatch("aab","c*a*b") << std::endl;
    std::cout << "aaabbbbb, c*a*a.ab* " << s.isMatch("aaabbbbb","c*a*a.ab*") << std::endl;
    std::cout << "aaaaacbb, a*a.bb " << s.isMatch("aaaaacbb","a*a.bb") << std::endl;
    std::cout << "aaa, ab*a*c*a " << s.isMatch("aa","ab*a*c*a") << std::endl;
}

/*
   Implement strStr().

   Returns a pointer to the first occurrence of needle in haystack, or null if
   needle is not part of haystack.
*/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
     char *strStr(char *haystack, char *needle) {
         if (!haystack || !needle) return NULL;
         string hs(haystack), ns(needle);
         if (!ns.length()) return haystack;
         if (hs.length() < ns.length()) return NULL;
         
         for (int i = 0; i <= hs.length() - ns.length(); i++) {
             int idx = i, j;
             for (j = 0; j < ns.length(); j++,idx++) {
                if (hs[idx] != ns[j]) break;
             }
             if (j == ns.length()) return haystack+i;
         }
         return NULL;
     }
};

int main()
{
    Solution s;

    std::cout << s.strStr("", "a") << endl;

    std::string s1, s2;
    for (int i = 0; i < 65536; i++) {
        s1.insert(0, "a");
        if (i % 2) s2.insert(0, "a");
    }
    s1.insert(s1.end(), 'b');
    s2.insert(s2.end(), 'b');
    s.strStr((char*)s1.c_str(), (char*)s2.c_str());
    const char* ret = s.strStr("", "");
    std::cout << ret << std::endl;
    std::cout << "abcdefg cd " << s.strStr("abcdefg", "cd") << std::endl;
    std::cout << "abcdefg abc " << s.strStr("abcdefg", "abc") << std::endl;
    std::cout << "abcdefg cdf " << s.strStr("abcdefg", "cdf") << std::endl;
}

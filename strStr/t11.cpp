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
         int hlen = strlen(haystack), nlen = strlen(needle);
         if (hlen < nlen) return NULL;
         char *h, *n;
         
         for (int i = 0; i <= hlen-nlen; i++) {
             h = haystack+i;
             n = needle;
             while (*h && *n && *h == *n) {n++;h++;}
             if (!*n) return haystack+i;
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

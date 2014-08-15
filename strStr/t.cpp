/*
   Implement strStr().

   Returns a pointer to the first occurrence of needle in haystack, or null if
   needle is not part of haystack.
*/

#include <iostream>
#include <string>
#include <string.h>

class Solution {
public:
     bool isSameStr(const char* p1, const char* p2) {
         while (*p1 && *p2) {
             if (*p1 != *p2) return false;
             p1++;
             p2++;
         }

         return (!*p2);
     }

     char *strStr(char *haystack, char *needle) {
         if (!haystack || !needle) return NULL;
         int len1 = strlen(haystack);
         int len2 = strlen(needle);
         if (len1 < len2) return NULL;
         if (!len2) return haystack;

         char *p = haystack;

         while (p < (haystack+len1-len2+1)) {
             while (*p && *p != *needle) p++;
             if (!*p) return NULL;
             if (isSameStr(p, needle)) return p;
             p++;
         }

         return NULL;
     }
};

int main()
{
    Solution s;

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

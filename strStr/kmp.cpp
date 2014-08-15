/*
   Implement strStr().

   Returns a pointer to the first occurrence of needle in haystack, or null if
   needle is not part of haystack.
*/

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

// This is implementation of KMP, which is fairly complicated.
// Following link explains it rather well:
// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

class Solution {
public:
 /* 
    aux[i] = the longest proper prefix of nd[0..i] 
    which is also a suffix of nd[0..i]. 
    Examples:
    For the pattern AABAACAABAA, aux[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
    For the pattern ABCDE, aux[] is [0, 0, 0, 0, 0]
    For the pattern AAAAA, aux[] is [0, 1, 2, 3, 4]

 */
     void computeAuxArray(string &nd, vector<int> &aux) {
         unsigned int start = 0, end = 1;

         aux[0] = 0;
         while (end < nd.length()) {
             if (nd[start] == nd[end]) {
                 aux[end++] = ++start;
             }
             else if (start) {
                 start = aux[start-1];
             }
             else {
                 aux[end++] = 0;
             }
         }
     }

     char *strStr(char *haystack, char *needle) {
         if (!haystack || !needle || strlen(haystack) < strlen(needle)) {
             return NULL;
         }
         string hs(haystack);
         string nd(needle);

         if (!nd.length()) return haystack;
         vector<int> aux(nd.length(), 0);
         computeAuxArray(nd, aux);
         
         // kmp algorithm
         unsigned int h = 0, n = 0;
         while (h < hs.length()) {
             if (hs[h] == nd[n]) {
                 h++; n++;
                 if (n == nd.length()) {
                     return (haystack+h-n);
                 }
             }
             else if (n) {
                 n = aux[n-1];
             }
             else {
                 h++;
             }
         }
         return NULL;
     }
};

int main()
{
    Solution s;

    std::cout << "bbbbababbbaabbba abb " << s.strStr("bbbbababbbaabbba", "abb") << std::endl;
    std::cout << "mississippi issip " << s.strStr("mississippi", "issip") << std::endl;
    std::string s1, s2;
    for (int i = 0; i < 65536; i++) {
        s1.insert(0, "a");
        if (i % 2) s2.insert(0, "a");
    }
    s1.insert(s1.end(), 'b');
    s2.insert(s2.end(), 'b');
    s.strStr((char*)s1.c_str(), (char*)s2.c_str());
    char* ret = s.strStr("", "");
    std::cout << ret << std::endl;
    std::cout << "abcdeccdccfg ccdcc " << s.strStr("abcdeccdccfg", "ccdcc") << std::endl;
    std::cout << "abcdefg cd " << s.strStr("abcdefg", "cd") << std::endl;
    std::cout << "abcdefg abc " << s.strStr("abcdefg", "abc") << std::endl;
    std::cout << "abcdefg cdf " << s.strStr("abcdefg", "cdf") << std::endl;
}

/*
   Given a string s consists of upper/lower-case alphabets and empty space
   characters ' ', return the length of last word in the string.
   If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space
characters only.
For example, 
Given s = "Hello World",
return 5.
*/

#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
     int lengthOfLastWord(const char *s) {
         if (!s) return 0;
         int len = strlen(s);
         int ret = 0;

         const char* p = s + (len-1);
         while (p >= s) {
             if (*p != ' ') {
                 ret++;
             }
             else if (ret) {
                 break;
             }
             p--;
         }

         return ret;
     }
};

int main()
{
    Solution s;
    const char *str = "a ";
    int ret;

    ret = s.lengthOfLastWord(str);
    cout << ret << endl;
}


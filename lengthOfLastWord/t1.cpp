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
#include <sstream>
using namespace std;

class Solution {
public:
     int lengthOfLastWord(const char *s) {
         string str(s);
         istringstream is(str);
         string word;

         while (is) {
             is >> word;
         } 

         return word.length();
     }
};

int main()
{
    Solution s;
    const char *str = "hello world ";
    int ret;

    ret = s.lengthOfLastWord(str);
    cout << ret << endl;
}


/*
   A message containing letters from A-Z is being encoded to numbers using the
   following mapping:
   'A' -> 1
   'B' -> 2
   ...
   'Z' -> 26

   Given an encoded message containing digits, determine the total number of
   ways to decode it.
   For example,
   Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
   The number of ways decoding "12" is 2.
*/

#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
     bool isChar(string sub) {
         if (sub[0] == '0') return false;
         int val = atoi(sub.c_str());
         return (val > 0 && val < 27);
     }
     int numDecodings(string s) {
         int len = s.length();
         if (!len) return 0;
         int p[len+1];
         p[0] = 1;
         p[1] = s[len-1] == '0' ? 0 : 1;

         for (int i = 2; i <= len; i++) {
             if (isChar(s.substr(len-i, 2))) {
                 p[i] = p[i-1]+p[i-2];
             }
             else if (s[len-i] != '0') {
                 p[i] = p[i-1];
             }
             else {
                 p[i] = 0;
             }
         }

         return p[len];
     }
};

int main()
{
    Solution s;
    int ret;
    string str = "01";

    ret = s.numDecodings(str);
    cout << ret << endl;

    str = "10";
    ret = s.numDecodings(str);
    cout << ret << endl;

    str = "101011";
    ret = s.numDecodings(str);
    cout << ret << endl;
}

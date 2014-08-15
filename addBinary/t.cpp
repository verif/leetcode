/*
   Given two binary strings, return their sum (also a binary string).
   For example,
   a = "11"
   b = "1"
   Return "100".
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
     string addBinary(string a, string b) {
         int lena = a.length();
         int lenb = b.length();

         if (!lena) return b;
         if (!lenb) return a;

         string ret;
         int len = min(lena, lenb);

         bool carry = false;
         char digit;
         int i;
         for (i = 0; i < len; i++) {
             if (a[lena-1-i] == '1' && b[lenb-1-i] == '1') {
                 digit = carry ? '1' : '0';
                 carry = true;
             } 
             else if (a[lena-1-i] == '0' && b[lenb-1-i] == '1') {
                 digit = carry ? '0' : '1';
             }
             else if (a[lena-1-i] == '1' && b[lenb-1-i] == '0') {
                 digit = carry ? '0' : '1';
             }
             else {
                 digit = carry ? '1' : '0';
                 carry = false;
             }
             ret.insert(ret.begin(), digit);
         }

         int maxLen = max(lena, lenb);
         for (;  i < maxLen; i++) {
             char c = lena > lenb ? a[maxLen-1-i] : b[maxLen-1-i];
             if (c == '1') {
                 digit = carry ? '0' : '1';
             }
             else {
                 digit = carry ? '1' : '0';
                 carry = false;
             }
             ret.insert(ret.begin(), digit);
         }

         if (carry) ret.insert(ret.begin(), '1');
         return ret;
     }
};

int main()
{
    Solution s;
    string ret;

    string a = "111111";
    string b = "111111";

    ret = s.addBinary(a,b);
    cout << ret << endl;

    a = "1010";
    b = "1011";
    ret = s.addBinary(a,b);
    cout << ret << endl;

    a = "100";
    b = "110010";
    ret = s.addBinary(a,b);
    cout << ret << endl;
}


/*
   Given two numbers represented as strings, return multiplication of the
   numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream
#include <stdlib.h>
using namespace std;

class Solution {
public:
     string multiply(string num1, string num2) {
         int len1 = num1.length();
         int len2 = num2.length();
         int carry = 0;
         string ret;

         for (int i = 0; i <= (len1+len2); i++) {
             int digit = carry;
             for (int j = 0; j <= i && j < len1; j++) {
                 int k = i-j;
                 if (k >= len2) continue;
                 int n1 = num1[len1-1-j] - '0';
                 int n2 = num2[len2-1-k] - '0';
                 int res = n1 * n2;
                 digit += res;
             }
             char c = '0' + digit % 10;
             ret.insert(ret.begin(), c);
             carry = digit/10;
         }

         // remove '0' at the beginning
         while (ret[0] == '0') {
             if (ret.length() == 1) break;
             ret.erase(ret.begin());
         }
         return ret;
     }
};

int main()
{
    Solution s;
    string ret;

    ret = s.multiply("0", "0");
    cout << ret << endl;

    ret = s.multiply("4", "6");
    cout << ret << endl;
    ret = s.multiply("14", "16");
    cout << ret << endl;

    ret = s.multiply("498828660196", "840477629533");
    cout << ret << endl;
    ret = s.multiply("6913259244", "71103343");
    cout << ret << endl;
    ret = s.multiply("123456789", "987654321");
    cout << ret << endl;
}

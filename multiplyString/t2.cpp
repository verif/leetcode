/*
   Given two numbers represented as strings, return multiplication of the
   numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
     string multiply(string num1, string num2) {
        string ret;
        if (!num1.length() || !num2.length()) return ret;
        
        int carry = 0, len1 = num1.length(), len2 = num2.length();
        for (int pos = 0; pos < len1+len2; pos++) {
            int digit = carry;
            for (int i = 0; i < len1; i++) {
                int j = pos-i;
                if (j < 0 || j >= len2) continue;
                digit += (num1[len1-1-i] -'0') * (num2[len2-1-j] - '0');
            }
            carry = (digit/10);
            digit %= 10;
            ret.insert(ret.begin(), '0'+digit);
        }
        while (ret[0] == '0' && ret.length() > 1) ret.erase(ret.begin());
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

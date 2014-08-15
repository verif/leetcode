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
         long long unsigned n1 = atoll(num1.c_str());
         long long unsigned n2 = atoll(num2.c_str());
         long long unsigned result = n1 * n2;
         ostringstream s;
         s << result;
         return s.str();
     }
};

int main()
{
    Solution s;
    string ret;

    ret = s.multiply("498828660196", "840477629533");
    cout << ret << endl;
    ret = s.multiply("6913259244", "71103343");
    cout << ret << endl;
    ret = s.multiply("123456789", "987654321");
    cout << ret << endl;

    return 0;
}

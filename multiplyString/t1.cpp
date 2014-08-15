/*
   Given two numbers represented as strings, return multiplication of the
   numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
     string multiply(string num1, string num2) {
        string ret;
        if (!num1.length() || !num2.length()) return ret;
        
        vector<int> res(num1.length() + num2.length(), 0);
        int i, j;
        for (i = num1.length()-1; i >= 0; i--) {
            for (j = num2.length()-1; j >= 0; j--) {
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                int idx = num1.length()-i-1+num2.length()-j-1;
                res[idx] += (d1*d2) % 10;
                res[idx+1] += (d1*d2) / 10;
            }
        }
        
        for (i = 0; i < res.size(); i++) {
            ret.insert(ret.begin(), '0' + (res[i] % 10));
            if (res[i] / 10) res[i+1] += res[i]/10;
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

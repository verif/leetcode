/*
   The count-and-say sequence is the sequence of integers beginning as follows:
   1, 11, 21, 1211, 111221, ...
   1 is read off as "one 1" or 11.
   11 is read off as "two 1s" or 21.
   21 is read off as "one 2, then one 1" or 1211.
   Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// recursive solution should be easy
class Solution {
public:
     string countAndSay(int n) {
         string ret;
         if (!n) return ret;
         if (n == 1) return "1";
         string str = countAndSay(n-1);
         int i = 0;
         ostringstream ss;
         while (i < str.length()) {
             char cur = str[i];
             int cnt = 0;
             while (str[i] == cur && i < str.length()) {
                 i++;
                 cnt++;
             }
             int val = cur-'0';
             ss << cnt << val;
         }
         return ss.str();
     }
};

int main()
{
    Solution s;
    string ret;

    for (int i = 0; i < 10; i++) {
        ret = s.countAndSay(i);
        cout << ret << endl;
    }
}

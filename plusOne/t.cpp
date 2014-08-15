/*
   Given a non-negative number represented as an array of digits, plus one to
   the number.

   The digits are stored such that the most significant digit is at the head of
   the list.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     vector<int> plusOne(vector<int> &digits) {
         vector<int> ret;
         bool carryOver = true;
         for (int i = 0; i < digits.size(); i++) {
             int digit = digits[digits.size() - 1 - i];
             if (carryOver) digit++;
             if (digit < 10) {
                 carryOver = false;
             }
             else digit = 0;
             ret.insert(ret.begin(), digit);
         }
         if (carryOver) ret.insert(ret.begin(), 1);
         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> ret;
    vector<int> digits = {9,9,9,9,9,9};

    ret = s.plusOne(digits);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
    }
    cout << endl;
}


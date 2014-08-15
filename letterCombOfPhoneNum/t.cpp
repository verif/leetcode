/*
   Given a digit string, return all possible letter combinations that the
   number could represent.
   A mapping of digit to letters (just like on the telephone buttons) is given
   below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in
any order you want.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
     void letterCombinationsRecur(string& digits, int idx, vector<string>& res,
                                  string& comb, vector<string> &mapping) {
         if (idx == (int) digits.length()) {
             res.push_back(comb);
             return;
         }
         int digit = digits[idx] - '0';
         string letters = mapping[digit];
         for (unsigned int i = 0; i < letters.length(); i++) {
             char c = letters[i];
             comb.push_back(c);
             letterCombinationsRecur(digits, idx+1, res, comb, mapping);
             comb.pop_back();
         }
     }
     vector<string> letterCombinations(string digits) {
         vector<string> mapping = {"_", "%", "abc", "def", "ghi", "jkl", "mno",
             "pqrs", "tuv", "wxyz"};
         vector<string> ret;
         string comb;
         letterCombinationsRecur(digits, 0, ret, comb, mapping);
         return ret;
     }
};

int main()
{
    Solution s;
    vector<string> ret;
 
    string digits = "23";
    ret = s.letterCombinations(digits);
    for (unsigned int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ",";
    } 
    cout << endl;
}

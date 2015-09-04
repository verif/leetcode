/*
   Given n pairs of parentheses, write a function to generate all combinations
   of well-formed parentheses.

   For example, given n = 3, a solution set is:
   "((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
     void placeOneParentheses(int left, int right,  int n, string sol,
                              vector<string> &res)
     {
         if (left == n) {
             int len = sol.length();
             for (int i = len; i < n*2; i++) {
                 sol.insert(sol.end(), ')');
             }
             res.push_back(sol);
             return;
         }
         if (left == right) {
             sol.insert(sol.end(), '(');
             left++;
             placeOneParentheses(left, right, n, sol, res);
         }
         else if (left > right) {
             sol.push_back('(');
             placeOneParentheses(left+1, right, n, sol, res);
             sol.erase(sol.length()-1, 1);
             sol.push_back(')');
             placeOneParentheses(left, right+1, n, sol, res);
             sol.erase(sol.length()-1, 1);
         }
     }
     vector<string> generateParenthesis(int n) {
         vector<string> res;
         if (!n) return res;
         string sol;

         placeOneParentheses(0, 0, n, sol, res);

         return res;
     }
};

int main()
{
    Solution s;
    vector<string> ret;

    ret = s.generateParenthesis(4);

    for (unsigned int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ",";
    }
    cout << endl;
}

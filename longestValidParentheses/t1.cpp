/*
   Given a string containing just the characters '(' and ')', find the length
   of the longest valid (well-formed) parentheses substring.

   For "(()", the longest valid parentheses substring is "()", which has length
   = 2.
   Another example is ")()())", where the longest valid parentheses substring
   is "()()", which has length = 4.
*/

#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
     int longestValidParentheses(string s) {
        int mx = 0;
        if (!s.length()) return 0;
        vector<int> res(s.length(), 0);
        stack<int> stk;
        
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] == '(') stk.push(i);
            else if (!stk.empty()) {
                int idx = stk.top();
                res[i] = i-idx+1;
                stk.pop();
                if (idx > 0 && res[idx-1]) {
                    res[i] += res[idx-1];
                }
                mx = std::max(mx, res[i]);
            }
        }
        return mx;
     }
};

int main()
{
    Solution s;

    cout << "(() is: " << s.longestValidParentheses("(()") << endl;
    cout << ")()()) is: " << s.longestValidParentheses(")()())") << endl;
    cout << "()(() is: " << s.longestValidParentheses("()(()") << endl;
    cout << "(()(((() is: " << s.longestValidParentheses("(()(((()") << endl;
    cout << "()(())((()())()) is: " <<
        s.longestValidParentheses("()(())((()())())") << endl;
    cout << "()((())((()())()) is: " <<
        s.longestValidParentheses("()((())((()())())") << endl;
}


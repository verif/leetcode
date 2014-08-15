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
#include <stack>
using namespace std;

class Solution {
public:
     int longestValidParentheses(string s) {
         stack<int> lstack; // left parentheses stack
         int len = s.length();
         if (!len) return 0;
         int lastReduced[len];

         int left = 0;
         int maxLen = 0;
         int curLen = 0;
         int prevLen = 0;
         for (int i = 0; i < len; i++) {
             lastReduced[i] = 0;
             if (s[i] == ')') {
                 if (!left) {
                     prevLen = 0;
                     continue;
                 }
                 int lastLeft = lstack.top();
                 lstack.pop();
                 left--;
                 curLen += 2;
                 curLen = prevLen = curLen + lastReduced[lastLeft];
                 maxLen = maxLen < prevLen ? prevLen : maxLen;
             }
             else {
                 if (curLen) {
                     lastReduced[i] = prevLen;
                 }
                 curLen = 0;
                 lstack.push(i);
                 left++;
             }
         }
         return maxLen;
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


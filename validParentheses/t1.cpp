/*
   Given a string containing just the characters '(', ')', '{', '}', '[' and
   ']', determine if the input string is valid.

   The brackets must close in the correct order, "()" and "()[]{}" are all
   valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
     bool isValid(string s) {
        stack<char> stk;
        
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty()) return false;
                char c = stk.top();
                stk.pop();
                if (s[i] == ')' && c != '(') return false;
                if (s[i] == '}' && c != '{') return false;
                if (s[i] == ']' && c != '[') return false;
            }
        }
        
        return stk.empty();
     }
};

int main()
{
    Solution s;
    cout << "() " << s.isValid("()") << endl;
    cout << "()[]{} " << s.isValid("()[]{}") << endl;
    cout << "(] " << s.isValid("(]") << endl;
    cout << "([)] " << s.isValid("([)]") << endl;
    cout << "[ " << s.isValid("[") << endl;
}

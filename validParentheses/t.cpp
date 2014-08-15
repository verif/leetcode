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
         int i1 = 0;
         int i2 = 0;
         int i3 = 0;
         stack<char> stc;
         for (unsigned int i = 0; i < s.length(); i++) {
             if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                 stc.push(s[i]);
                 if (s[i] == '(') i1++;
                 if (s[i] == '[') i2++;
                 if (s[i] == '{') i3++;
             }
             else {
                 if (stc.empty()) return false;
                 char c = stc.top();
                 stc.pop();
                 if (c == '(') {
                     if (s[i] != ')') return false;
                     i1--;
                     if (i1 < 0) return false;
                 }
                 if (c == '[') {
                     if (s[i] != ']') return false;
                     i2--;
                     if (i2 < 0) return false;
                 }
                 if (c == '{') {
                     if (s[i] != '}') return false;
                     i3--;
                     if (i3 < 0) return false;
                 }
             }
         }

         return stc.empty();
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

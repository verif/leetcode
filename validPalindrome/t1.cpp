/*
   Given a string, determine if it is a palindrome, considering only
   alphanumeric characters and ignoring cases.
   For example,
   "A man, a plan, a canal: Panama" is a palindrome.
   "race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to
ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAlphaNumeric(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' &&
c <= '9');
    }
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        
        while (start < end) {
            while (start < end && !isAlphaNumeric(s[start])) start++;
            while (start < end && !isAlphaNumeric(s[end])) end--;
            if (start >= end) break;
            if (s[start] == s[end]) { start++; end--; continue;}
            if (std::min(s[start], s[end]) >= 'A' && 
                abs(s[end]-s[start]) == ('a' - 'A')) {
                start++; end--; continue;
            }
            return false;
        }
        
        return true;
    }
};

int main()
{
    bool ret;
    Solution s;
    string str = "2a3";

    ret = s.isPalindrome(str);

    cout << ret << endl;
}

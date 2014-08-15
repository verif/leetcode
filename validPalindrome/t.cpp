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
     bool isPalindrome(string s) {
         if (s.length() < 2) return true;
         const char* p = s.c_str();
         const char* q = p + (s.length() - 1);
         while (p < q) {
             while (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') ||
                      (*p >= '0' && *p <= '9'))) {
                 p++;
                 if (p >= q) return true;
             }
             while (!((*q >= 'a' && *q <= 'z') || (*q >= 'A' && *q <= 'Z') ||
                      (*q >= '0' && *q <= '9'))) {
                 q--;
                 if (p >= q) return true;
             }
             if (!(*p == *q || (abs(*p-*q) == abs('a'-'A')))) {
                 return false;
             }
             p++;
             q--;
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

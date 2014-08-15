/*
   Given an input string, reverse the string word by word.
   For example,
   Given s = "the sky is blue",
   return "blue is sky the".

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing
spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
     void reverseWords(string &s) {
        istringstream iss(s);
        string ret, tmp;
        
        while (iss >> tmp) {
            ret.insert(0, tmp+" ");
        }
        if (!ret.empty()) ret.pop_back();
        s = ret;
     }
};

int main()
{
    string s;
    Solution sl;
    s = " " ;
    cout << "input string: " << s <<  endl;
    sl.reverseWords(s);
    cout << "reversed string is: " << "***" << s << "***" << endl;
}


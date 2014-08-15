/*
   Given an array of words and a length L, format the text such that each line
   has exactly L characters and is fully (left and right) justified.
   You should pack your words in a greedy approach; that is, pack as many words
   as you can in each line. Pad extra spaces ' ' when necessary so that each
   line has exactly L characters.
   Extra spaces between words should be distributed as evenly as possible. If
   the number of spaces on a line do not divide evenly between words, the empty
   slots on the left will be assigned more spaces than the slots on the right.
   For the last line of text, it should be left justified and no extra space is
   inserted between words.
   For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     string getPaddedString(vector<string> &words, int start, int end, int len,
                            int L, bool last)
     {
         string ret;
         int numSpaces = L-len;
         int numIntervals = (end-start);
         if (!numIntervals) {
             ret += words[start];
             for (int i = 0; i < (L-len); i++) ret += " ";
             return ret;
         }
         int perInterval = numSpaces/numIntervals;
         int remainingSpace = numSpaces - perInterval*numIntervals;

         for (int i = start; i <= end; i++) {
             ret += words[i];
             // insert spaces between words
             if (i == end) break;
             if (last) {
                 ret += " ";
                 continue;
             }
             for (int j = 0; j < perInterval; j++) {
                 ret += " ";
             }
             if (remainingSpace) {
                 ret += " ";
                 remainingSpace--;
             }
         }

         if (last) {
             for (int i = 0; i < (numSpaces-numIntervals); i++) {
                 ret += " ";
             }
         }
         return ret;
     }

     vector<string> fullJustify(vector<string> &words, int L) {
         vector<string> ret;
         int start = 0;
         int end = 0;
         int i = 0;
         int len = 0;

         while (i < words.size()) {
             if ((len + words[i].length() + (i-start)) > L) {
                 end = i-1;
                 string str = getPaddedString(words, start, end, len, L, false);
                 ret.push_back(str);
                 start = i;
                 len = 0;
             }
             len += words[i].length();
             i++;
         }

         string str = getPaddedString(words, start, i-1, len, L, true);
         ret.push_back(str);

         return ret;
     }
};

int main()
{
    Solution s;
    vector<string> ret;
    vector<string> words = {"This", "is", "an", "example", "of", "text",
        "justification."};

    ret = s.fullJustify(words, 16);

    std::cout << "[" << endl;
    for (int i = 0; i < ret.size(); i++) {
        std::cout << "  " << "\"" << ret[i] << "\"" << endl;
    }
    std::cout << "]" << endl;
}

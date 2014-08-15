/*
   Write a function to find the longest common prefix string amongst an array
   of strings.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
     string longestCommonPrefix(vector<string> &strs) {
         int num = strs.size();
         string ret;
         if (!num) return ret;
         if (num == 1) return strs[0];
         unsigned int i = 0;
         while (1) {
             char c = strs[0][i];
             bool cont = true;
             for (unsigned int j = 1; j < strs.size(); j++) {
                 if (strs[j].length() <= i || strs[j][i] != c) {
                     cont = false;
                     break;
                 }
             }
             if (!cont) break;
             ret.push_back(c);
             i++;
         }

         return ret;
     }
};

int main() {
    Solution s;
    vector<string> strs = {"aaa", "aaa", "aaaaaaa", "aaaaaaaaaaa"};
    string ret;

    ret = s.longestCommonPrefix(strs);
    cout << ret << endl;
}

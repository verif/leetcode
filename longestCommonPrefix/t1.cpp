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
        string ret;
        if (!strs.size()) return ret;
        
        int idx = 0;
        while (1) {
            for (unsigned int i = 0; i < strs.size(); i++) {
                if (strs[i].length() == idx || 
		    (i && strs[i][idx] != strs[i-1][idx])) return ret;
            }
            ret.push_back(strs[0][idx++]);
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

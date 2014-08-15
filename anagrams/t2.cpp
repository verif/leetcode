/*
   Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> // for 'sort'
#include <vector>
using namespace std;

class Solution {
public:
     vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> smap;
        vector<string> res;
        
        for (int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());
            smap[sorted].push_back(strs[i]);
        }
        
        unordered_map<string, vector<string>>::const_iterator it;
        for (it = smap.begin(); it != smap.end(); it++) {
            if (it->second.size() > 1) res.insert(res.begin(),
it->second.begin(), it->second.end());
        }
        return res;
     }
};

int main()
{
    Solution s;
    vector<string> ret;

    vector<string> strs = {"abc", "cba", "caa", "aac", "abd"};

    ret = s.anagrams(strs);

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ",";
    }
    cout << endl;
}

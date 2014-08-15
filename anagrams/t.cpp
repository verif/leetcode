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
         vector<string> ret;
         int total = strs.size();
         if (!total) return ret;
         unordered_map<string, vector<string>> strMap;
         unordered_map<string, vector<string>>::iterator it;
         for (int i = 0; i < total; i++) {
             string sortedStr = strs[i];
             sort(sortedStr.begin(), sortedStr.end());
             it = strMap.find(sortedStr);
             if (it != strMap.end()) {
                 it->second.push_back(strs[i]);
             }
             else {
                 vector<string> vs;
                 vs.push_back(strs[i]);
                 strMap[sortedStr] = vs;
             }
         }

         for (it = strMap.begin(); it != strMap.end(); it++) {
             vector<string> vs = it->second;
             if (vs.size() > 1) {
                 ret.insert(ret.end(), vs.begin(), vs.end());
             }
         }

         return ret;
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

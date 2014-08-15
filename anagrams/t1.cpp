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
     static unsigned long stringHash(string str) {
         sort(str.begin(), str.end());
         return std::hash<string>()(str);
     }
     static bool stringEq(string s1, string s2) {
         sort(s1.begin(), s1.end());
         sort(s2.begin(), s2.end());
         return !s1.compare(s2);
     }
     vector<string> anagrams(vector<string> &strs) {
         vector<string> ret;
         int total = strs.size();
         if (!total) return ret;
         unordered_map<string, int, function<unsigned long(string)>, 
                                    function<bool (string, string)> 
                                        >strMap(total, stringHash, stringEq);
         unordered_map<string, int, function<unsigned
             long(string)>>::iterator it;
         for (int i = 0; i < total; i++) {
             string str = strs[i];
             it = strMap.find(str);
             if (it != strMap.end()) {
                 it->second++;
             }
             else {
                 strMap[str] = 1;
             }
         }

         for (int i = 0; i < total; i++) {
             if (strMap[strs[i]] > 1) {
                 ret.push_back(strs[i]);
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

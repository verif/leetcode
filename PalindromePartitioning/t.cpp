/*
   Given a string s, partition s such that every substring of the partition is
   a palindrome.
   Return all possible palindrome partitioning of s.
   For example, given s = "aab",
   Return
     [
        ["aa","b"],
        ["a","a","b"]
     ]
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
     bool isPalindrome(string s) {
         int i = 0;
         int j = s.length()-1;

         while (j > i) {
             if (s.at(i) != s.at(j)) return false;
             i++;
             j--;
         }
         return true;
     }
     vector<vector<string>> partition(string s) {
         unordered_map<string, vector<vector<string>>>::const_iterator it =
             strMap.find(s);
         if (it != strMap.end()) {
             return it->second;
         }
         vector<vector<string>> ret;
         int len = s.length();
         int i;
         for (i = 1; i <= len; i++) {
             string subStr1 = s.substr(0, i);
             if (!isPalindrome(subStr1)) continue;
             if (i == len) {
                 vector<string> v1;
                 v1.push_back(s);
                 ret.push_back(v1);
                 break;
             }
             string subStr2 = s.substr(i, len-i);
             vector<vector<string>> v2 = partition(subStr2);
             for (vector<vector<string>>::const_iterator it = v2.begin(); it!=
                  v2.end(); it++) {
                 vector<string> v3 = *it;
                 v3.insert(v3.begin(), subStr1);
                 ret.push_back(v3);
             }
         }

         return ret;
     }
private:
     unordered_map<string, vector<vector<string>>> strMap;
};

static void printPartition(vector<vector<string>>  vv) {
    cout << "[" << endl;
    for (vector<vector<string>>::const_iterator it = vv.begin(); it !=
         vv.end(); it++) {
        cout << "   [" ;
        vector<string> v = *it;
        for (vector<string>::const_iterator it2 = v.begin(); it2 != v.end();
             it2++) {
            cout << *it2 << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<vector<string>> ret;

    ret = s.partition("abcddcab");
    printPartition(ret);
}

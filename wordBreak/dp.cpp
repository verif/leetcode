/*
   Given a string s and a dictionary of words dict, add spaces in s to
   construct a sentence where each word is a valid dictionary word.
   Return all such possible sentences.

   For example, given
   s = "catsanddog",
   dict = ["cat", "cats", "and", "sand", "dog"].
   A solution is ["cats and dog", "cat sand dog"].
*/

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> setHash;
public:
     vector<string> wordBreak(string s, unordered_set<string> &dict) {
         unsigned int len = s.length();
         vector<string> p[len+1];

         for (unsigned int i = 1; i <= len; i++) {
             for (unsigned int j = 1; j <= i; j++) {
                 string sub = s.substr(len-i, j);
                 if (dict.find(sub) != dict.end() && 
                     (i == j || !p[i-j].empty())) {
                     if (i == j) {
                         p[i].push_back(sub);
                         continue;
                     }
                     for (unsigned int k = 0; k < p[i-j].size(); k++) {
                         p[i].push_back(sub+" "+p[i-j][k]);
                     }
                 }
             }
         }
         return p[len];
     }
};

int main() {
    Solution s;
    unordered_set<string> dict;
    string str = "catsanddog";
    vector<string> ret;

    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    //dict.insert("s");

    ret = s.wordBreak(str, dict);
    for (vector<string>::const_iterator it = ret.begin(); it != ret.end();
         it++) {
        cout << *it << endl;
    }
}

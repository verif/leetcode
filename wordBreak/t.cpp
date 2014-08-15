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
         vector<string>  sentenceSet;

         unordered_map<string, vector<string>>::const_iterator it =
             setHash.find(s);
         if (it != setHash.end()) {
             return it->second;
         }

         int len = s.length();
         
         for (int i = 1; i <= len; i++) {
             string sub = s.substr(0, i);
             unordered_set<string>::const_iterator it = dict.find(sub);
             if (it == dict.end()) {
                 continue;
             }
             else {
                 if (i == len) {
                     sentenceSet.push_back(sub);
                     break;
                 }
                 string remain = s.substr(i, len-i);
                 vector<string> subSet = wordBreak(remain, dict);

                 for (vector<string>::iterator it = subSet.begin(); it !=
                      subSet.end(); it++) {
                     string str = *it;
                     str = sub + " " + str;
                     sentenceSet.push_back(str);
                 }
             }
         }

         pair<string, vector<string>> p(s, sentenceSet);
         setHash.insert(p);

         return sentenceSet;
     }
};

int main() {
    Solution s;
    unordered_set<string> dict;
    string str = "catsanddogcats";
    vector<string> ret;

    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    dict.insert("s");

    ret = s.wordBreak(str, dict);
    for (vector<string>::const_iterator it = ret.begin(); it != ret.end();
         it++) {
        cout << *it << endl;
    }
}

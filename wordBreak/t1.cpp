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
    unordered_map<string, bool> setHash;
public:
     bool wordBreak(string s, unordered_set<string> &dict) {

         unordered_map<string, bool>::const_iterator it =
             setHash.find(s);
         if (it != setHash.end()) {
             return it->second;
         }

         int len = s.length();
         bool ret = false;
         
         for (int i = 1; i <= len; i++) {
             string sub = s.substr(0, i);
             unordered_set<string>::const_iterator it = dict.find(sub);
             if (it == dict.end()) {
                 continue;
             }
             else {
                 if (i == len) {
                     ret = true;
                     break;
                 }
                 string remain = s.substr(i, len-i);
                 if (wordBreak(remain, dict)) {
                     ret = true;
                     break;
                 }
             }
         }

         pair<string, bool> p(s, ret);
         setHash.insert(p);

         return ret;
     }
};

int main() {
    Solution s;
    unordered_set<string> dict;
    string str = "catsanddogcats";
    bool ret;

    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    dict.insert("s");

    ret = s.wordBreak(str, dict);
    cout << ret << endl;

    return 0;
}

/*
   Given a string S and a string T, find the minimum window in S which will
   contain all the characters in T in complexity O(n).
   For example,
   S = "ADOBECODEBANC"
   T = "ABC"
   Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the
emtpy string "".
If there are multiple such windows, you are guaranteed that there will always
be only one unique minimum window in S.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    typedef unordered_map<char, int> cmap;
public:
     string minWindow(string S, string T) {
         int start = -1;
         int cnt = 0;
         int i;
         cmap m;
         int total = 0;
         string ret;

         if (!T.length() || !S.length()) return ret;

         // first find uniq chars in 'T'
         for (i = 0; i < T.length(); i++) {
             if (m.find(T[i]) == m.end()) {
                 total++;
                 m[T[i]] = -1;
             }
         }

         for (i = 0; i < S.length(); i++) {
             cmap::iterator it = m.find(S[i]);
             if (it != m.end()) {
                 if (it->second == -1) { // first time find 'S[i]'
                     if (!cnt) start = i;
                     cnt++;
                     if (cnt == total) { // find all uniq chars
                         ret = S.substr(start, i-start+1);
                     }
                 }
                 else {
                     if (start == it->second) {
                         start++;
                         while (start < i) {
                             cmap::iterator it2 = m.find(S[start]);
                             if (it2 != m.end() && it2->second == start) {
                                 break;
                             }
                             start++;
                         }
                     }
                     if (cnt == total) {
                         if (ret.length() > (i-start+1)) {
                             ret = S.substr(start, i-start+1);
                         }
                     }
                 }
                 it->second = i;
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;
    string S = "ADOBECODEBANC";
    string T = "ABC";
    string ret;

    ret = s.minWindow(S, T);
    cout << ret << endl;

    S = "ACCBCCACB";
    T = "ABCAC";
    ret = s.minWindow(S, T);
    cout << ret << endl;

    return 0;
}


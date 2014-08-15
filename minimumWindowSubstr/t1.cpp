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
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
     string minWindow(string S, string T) {
         int tlen = T.length();
         int slen = S.length();
         if (!slen) return S;
         if (!tlen) return T;

         vector<int> cntArr(256, 0);
         vector<int> curCntArr(256, 0);
         int total = 0;

         for (int i = 0; i < tlen; i++) {
             cntArr[T[i]]++;
             total++;
         }

         int minW = INT_MAX;
         int start = 0;
         string ret;
         int cnt = 0;
         for (int i = 0; i < slen; i++) {
             if (!cntArr[S[i]]) continue;
             if (curCntArr[S[i]] < cntArr[S[i]]) {
                 cnt++;
             }
             curCntArr[S[i]]++;
             if (cnt < total) continue;
             while (start < i) {
                 if (!cntArr[S[start]]) { start++; continue;}
                 if (curCntArr[S[start]] > cntArr[S[start]]) {
                     curCntArr[S[start]]--;
                     start++;
                     continue;
                 }
                 break;
             }
             if (minW > (i-start+1)) {
                 minW = i-start+1;
                 ret = S.substr(start, minW);
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

    S = "acacacbcacbcbaba";
    T = "aabb";
    ret = s.minWindow(S, T);
    cout << ret << endl;

    return 0;
}


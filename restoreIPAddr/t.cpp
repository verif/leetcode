/*
   Given a string containing only digits, restore it by returning all possible
   valid IP address combinations.

   For example:
   Given "25525511135",
   return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Use dynamic programming
class Solution {
public:
     bool isValidIPSeg(string seg) {
         int val = atoi(seg.c_str());
         if (val < 0 || val > 255) return false;
         if (val && seg[0] == '0') return false;
         if (!val && seg.length() > 1) return false;
         return true;
     }
     void combineStr(string sub, vector<string>& prev, vector<string>& cur) {
         for (int i = 0; i < prev.size(); i++) {
             string ns = sub+"."+prev[i];
             cur.push_back(ns);
         }
     }
     vector<string> restoreIpAddresses(string s) {
         int len = s.length();
         vector<string> p[len+1][5];
         vector<string> empty;
         int i, j;

         if (len < 4) return empty;

         // set initial condition
         string sub = s.substr(len-1, 1);;
         vector<string> v;
         if (isValidIPSeg(sub)) {
             v.push_back(sub);
             p[1][1] = v;
         }
         sub = s.substr(len-2, 2);;
         vector<string> v2;
         if (isValidIPSeg(sub)) {
             v2.push_back(sub);
             p[2][1] = v2;
         }
         sub = s.substr(len-3, 3);;
         vector<string> v3;
         if (isValidIPSeg(sub)) {
             v3.push_back(sub);
             p[3][1] = v3;
         }

         for (i = 2; i <= len; i++) {
             int jmax = i > 4 ? 4 : i;
             for (j = 2; j <= jmax; j++) {
                 sub = s.substr(len-i, i);
                 if (isValidIPSeg(sub.substr(0, 1)) && !p[i-1][j-1].empty()) {
                     combineStr(sub.substr(0, 1), p[i-1][j-1], p[i][j]);
                 }
                 if (isValidIPSeg(sub.substr(0, 2)) && !p[i-2][j-1].empty()) {
                     combineStr(sub.substr(0, 2), p[i-2][j-1], p[i][j]);
                 }
                 if (i > 2 && isValidIPSeg(sub.substr(0, 3)) &&
                     !p[i-3][j-1].empty()) {
                     combineStr(sub.substr(0, 3), p[i-3][j-1], p[i][j]);
                 }
             }
         }

         return p[len][4];
     }
};

int main()
{
    Solution s;
    vector<string> ret;
    string str = "010010";

    ret = s.restoreIpAddresses(str);
    cout << "[";
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ", ";
    } 
    cout << "]" << endl;;
}

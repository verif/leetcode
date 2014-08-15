/*
   Given an unsorted array of integers, find the length of the longest
   consecutive elements sequence.
   For example,
   Given [100, 4, 200, 1, 3, 2],
   The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
length: 4.
Your algorithm should run in O(n) complexity.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

using namespace std;

class Solution {
public:
     int longestConsecutive(vector<int> &num) {
         if (num.size() < 2) return num.size();
         unordered_map<int, int> seq;
         int maxLen = 0;
         unordered_map<int,int>::iterator it;
         for (int i = 0; i < num.size(); i++) {
             int val = num[i];
             int idx = val;
             it = seq.find(val);
             if (it != seq.end()) continue;
             it = seq.find(val-1);
             if (it != seq.end()) {
                 it->second = val;
             }
             it = seq.find(val+1);
             if (it != seq.end()) {
                 idx = val+1;
             }
             pair<int, int> p(val, idx);
             seq.insert(p);
         }
         // Now scan 'seq' to get the max sequence
         unordered_map<int, int> m;
         while (!seq.empty()) {
             it = seq.begin();
             int len = 1;
             int start = it->first;
             int val = it->first;
             int next = it->second;
             while (val != next) { // have next value
                 seq.erase(it);
                 it = seq.find(next);
                 if (it == seq.end()) { // entry already erased
                     break;
                 }
                 val = it->first;
                 next = it->second;
                 len++;
             }
             int end = val;
             if (it != seq.end()) seq.erase(it);
             unordered_map<int, int>::iterator it2 = m.find(end+1);
             if (it2 != m.end()) {
                 len += it2->second;
             }
             pair<int, int> p(start, len);
             m.insert(p);
             maxLen = maxLen < len ? len : maxLen;
         }
         return maxLen;
     }
};

int main()
{
    Solution s;
    int ret;
    vector<int> num = {1, 2, 3, 4, 5, 6};

    ret = s.longestConsecutive(num);
    cout << ret << endl;
}


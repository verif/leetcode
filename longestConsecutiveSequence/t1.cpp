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
#include <unordered_set>
using namespace std;

class Solution {
public:
     int longestConsecutive(vector<int> &num) {
         if (num.size() < 2) return num.size();

         unordered_set<int> numSet;
         unsigned int i;

         for (i = 0; i < num.size(); i++) {
             numSet.insert(num[i]);
         }

         int maxLen = 0;
         for (i = 0; i < num.size(); i++) {
             if (numSet.find(num[i]) == numSet.end()) continue;

             int len = 0;
             int val = num[i];
             while (numSet.find(val) != numSet.end()) {
                 numSet.erase(val);
                 len++;
                 val++;
             }
             val = num[i]-1;
             while (numSet.find(val) != numSet.end()) {
                 numSet.erase(val);
                 len++;
                 val--;
             }
             maxLen = maxLen < len ? len : maxLen;
         }
         return maxLen;
     }
};

int main()
{
    Solution s;
    int ret;
    vector<int> num = {1, 2, 3, 40, 5, 6};

    ret = s.longestConsecutive(num);
    cout << ret << endl;
}


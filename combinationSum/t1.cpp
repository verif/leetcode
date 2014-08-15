/*
   Given a set of candidate numbers (C) and a target number (T), find all
   unique combinations in C where the candidate numbers sums to T.
   The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ..., ak) must be in non-descending order.
(ie, a1 <= a2 ... <= ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3]
*/

#include <vector>
#include <iostream>
#include <algorithm> // for 'sort'
using namespace std;

class Solution {
public:
     void combinationSumRecur(vector<int> &num, int target, int index,
                               vector<vector<int>>& ret, vector<int> sol) {
         if (!target) {
             ret.push_back(sol);
             return;
         }
         if (target < 0 || index >= num.size()) return;
         int val = num[index];
         int next = index;
         while (num[next] == val && next < num.size()) {
             next++;
         }
         int times = target/val;
         for (int i = 0; i <= times; i++) {
             for (int j = 0; j < i; j++) {
                 sol.push_back(val);
             }
             combinationSumRecur(num, target-i*val, next, ret, sol);
             for (int j = 0; j < i; j++) {
                 sol.pop_back();
             }
         }
     }
     vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
         vector<vector<int>> ret;

         if (!candidates.size()) return ret;
         sort(candidates.begin(), candidates.end());
         int i = 0;
         vector<int> sol;
         combinationSumRecur(candidates, target, i, ret, sol);

         return ret;
     }
};

int main()
{
    Solution s;
    vector<vector<int>> ret;

    vector<int> num = {2,3,6,7};
    ret = s.combinationSum(num, 8);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
}

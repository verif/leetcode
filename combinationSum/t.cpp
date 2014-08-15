/*
   Given a collection of candidate numbers (C) and a target number (T), find
   all unique combinations in C where the candidate numbers sums to T.
   Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, .., ak) must be in non-descending order.
(ie, a1 <= a2 ... <= ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]
*/

#include <vector>
#include <iostream>
#include <algorithm> // for 'sort'
using namespace std;

class Solution {
public:
     void combinationSum2Recur(vector<int> &num, int target, int index,
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
         for (int i = index; i <= next; i++) {
             for (int j = 0; j < (i-index); j++) {
                 sol.push_back(val);
             }
             combinationSum2Recur(num, target-(i-index)*val, next, ret, sol);
             for (int j = 0; j < (i-index); j++) {
                 sol.pop_back();
             }
         }
     }
     vector<vector<int> > combinationSum2(vector<int> &num, int target) {
         vector<vector<int>> ret;

         if (!num.size()) return ret;
         sort(num.begin(), num.end());
         int i = 0;
         vector<int> sol;
         combinationSum2Recur(num, target, i, ret, sol);

         return ret;
     }
};

int main()
{
    Solution s;
    vector<vector<int>> ret;

    vector<int> num = {10,1,2,7,6,1,5};
    ret = s.combinationSum2(num, 8);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
}

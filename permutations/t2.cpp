/*
   Given a collection of numbers that might contain duplicates, return all
   possible unique permutations.

   For example,
   [1,1,2] have the following unique permutations:
   [1,1,2], [1,2,1], and [2,1,1].
*/

#include <vector>
#include <algorithm> // for 'sort'
#include <iostream>
using namespace std;

class Solution {
public:
     void permuteRecur(vector<int> &num, int size, vector<vector<int>> &results,
                       vector<int>& sol, vector<int>& visited) {
         if (!size) {
             results.push_back(sol);
             return;
         }

         for (int i = 0; i < num.size(); i++) {
             if (!visited[i]) {
                 if (i > 0 && num[i] == num[i-1] && !visited[i-1]) continue;
                 visited[i] = 1;
                 sol.push_back(num[i]);
                 permuteRecur(num, size-1, results, sol, visited);
                 sol.pop_back();
                 visited[i] = 0;
             }
         }
     }

     vector<vector<int>> permuteUnique(vector<int> &num) {
         vector<vector<int>> ret;
         if (!num.size()) return ret;
         vector<int> visited(num.size(), 0);
         vector<int> solution;

         sort(num.begin(), num.end());
         permuteRecur(num, num.size(), ret, solution, visited);

         return ret;
     }
};

int main()
{
    Solution s;

    vector<vector<int>> ret;
    vector<int> num = {1, 2, 1};

    ret = s.permuteUnique(num);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
}


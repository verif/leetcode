/*
   Given a collection of numbers, return all possible permutations.

   For example,
   [1,2,3] have the following permutations:
   [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <vector>
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
                 visited[i] = 1;
                 sol.push_back(num[i]);
                 permuteRecur(num, size-1, results, sol, visited);
                 sol.resize(sol.size()-1);
                 visited[i] = 0;
             }
         }
     }

     vector<vector<int>> permute(vector<int> &num) {
         vector<vector<int>> ret;
         if (!num.size()) return ret;
         vector<int> visited(num.size(), 0);
         vector<int> solution;

         permuteRecur(num, num.size(), ret, solution, visited);

         return ret;
     }
};

int main()
{
    Solution s;

    vector<vector<int>> ret;
    vector<int> num = {1, 2, 3};

    ret = s.permute(num);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
}


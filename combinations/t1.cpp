/*
   Given two integers n and k, return all possible combinations of k numbers
   out of 1 ... n.

   For example,
   If n = 4 and k = 2, a solution is:
   [
     [2,4],
     [3,4],
     [2,3],
     [1,2],
     [1,3],
     [1,4],
   ]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     void combineRecur(int start, int end, int sz, vector<int>& cur,
                  vector<vector<int>> &res) {
         if (cur.size() == sz) {
             res.push_back(cur);
             return;
         }

         for (int i = start; i <= end; i++) {
             cur.push_back(i);
             combineRecur(i+1, end, sz, cur, res);
             cur.pop_back();
         }
     }
     vector<vector<int> > combine(int n, int k) {
         vector<vector<int>> ret;
         if (n <= 0 || k <= 0 || k > n) return ret;
         vector<int> cur;
         combineRecur(1, n, k, cur, ret);
         return ret;
     }
};

int main()
{
    Solution s;
    vector<vector<int>> ret;

    ret = s.combine(6, 3);
    cout << "[" << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << "  [";
        vector<int> vec = ret[i];
        for (int j = 0; j < vec.size(); j++) {
            cout << vec[j] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}

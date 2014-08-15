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
     vector<vector<int> > combine(int n, int k) {
         vector<vector<int>> ret;
         if (n <= 0 || k <= 0 || k > n) return ret;
         
         vector<vector<int>> p[n+1][k+1];
         
         // initial condition
         vector<int> empty;
         p[0][0].push_back(empty);

         for (int i = 1; i <=n; i++) {
             p[i][0].push_back(empty);
             for (int j = 1; j <= i && j <= k; j++) {
                 if (i > j) p[i][j] = p[i-1][j];
                 for (int k1 = 0; k1 < p[i-1][j-1].size(); k1++) {
                     vector<int> v = p[i-1][j-1][k1];
                     v.push_back(i);
                     p[i][j].push_back(v);
                 }
             }
         }

         return p[n][k];
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

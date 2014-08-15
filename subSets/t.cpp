/*
   Given a collection of integers that might contain duplicates, S, return all
   possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <vector>
#include <iostream>
#include <algorithm> // for 'sort'
using namespace std;

class Solution {
public:
     vector<vector<int> > subsetsWithDup(vector<int> &S) {
         sort(S.begin(), S.end());
         vector<int> empty;
         vector<vector<int>> ret;

         ret.push_back(empty);
         int i = 0;
         while (i < S.size()) {
             int val = S[i];
             int num = 1;
             i++;
             while (i < S.size() && S[i] == val) {
                 i++;
                 num++;
             }
             int size = ret.size();
             for (int j = 0; j < size; j++) {
                 vector<int> vec = ret[j];
                 for (int k = 0; k < num; k++) {
                     vec.push_back(val);
                     ret.push_back(vec);
                 }
             }
         }
         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> S = {1,2,2,3,3,1};
    vector<vector<int>> ret;

    ret = s.subsetsWithDup(S);

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

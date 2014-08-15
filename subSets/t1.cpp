/*
   Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
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
    vector<vector<int>> subsets(vector<int> &S) {
        vector<vector<int>> ret;
        vector<int> v;
        ret.push_back(v);

        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); i++) {
            int size = ret.size();
            for (int j = 0; j < size; j++) {
                vector<int> v1 = ret[j];
                v1.push_back(S[i]);
                ret.push_back(v1);
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> S = {4, 1, 0};
    vector<vector<int>> ret;

    ret = s.subsets(S);

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

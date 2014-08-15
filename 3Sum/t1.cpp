/*
   Given an array S of n integers, are there elements a, b, c in S such that a
   + b + c = 0? Find all unique triplets in the array which gives the sum of
   zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2);
*/

#include <iostream>
#include <vector>
#include <algorithm> // for 'sort'
using namespace std;

class Solution {
public:
    void twoSum(vector<int> &num, int st, int target, vector<vector<int>> &res)
{
        int idx1 = st, idx2 = num.size()-1;
        while (idx1 < idx2) {
            int v1 = num[idx1], v2 = num[idx2];
            int sum = v1 + v2;
            if (sum == target) {
                vector<int> vec = {-target, num[idx1], num[idx2]};
                res.push_back(vec);
                while (idx1 < idx2 && num[idx1] == v1) idx1++;
            }
            else if (sum > target) idx2--;
            else idx1++;
        }
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        if (num.size() < 3) return res;
        
        std::sort(num.begin(), num.end());
        int first = 0;
        while (first < num.size()-2) {
            int val = num[first];
            twoSum(num, first+1, -val, res);
            while (first < num.size()-2 && num[first] == val) first++;
        }
        
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ret;
    vector<int> num = {-1,-1,-1,-1,-2,-2,-2,4, 0,0,0,0,0,0,0,1,1,1, 1, 2, -1, -4};

    ret = s.threeSum(num);
    unsigned int i, j;
    for (i = 0; i < ret.size(); i++) {
        for (j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;

    num = {0,0,0};
    ret = s.threeSum(num);
    for (i = 0; i < ret.size(); i++) {
        for (j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;

    num = {0,1,1};
    ret = s.threeSum(num);
    for (i = 0; i < ret.size(); i++) {
        for (j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;

    num = {0,0, -1, 1};
    ret = s.threeSum(num);
    for (i = 0; i < ret.size(); i++) {
        for (j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
}

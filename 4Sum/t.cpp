/*
   Given an array S of n integers, are there elements a, b, c, and d in S such
   that a + b + c + d = target? Find all unique quadruplets in the array which
   gives the sum of target.
Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie,
a<=b<=c<=d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
A solution set is:
     (-1,  0, 0, 1)
     (-2, -1, 1, 2)
     (-2,  0, 0, 2)
*/

#include <vector>
#include <iostream>
#include <algorithm> // for 'sort'
using namespace std;

class Solution {
public:
     bool oneSum(vector<int> &num, int start, int target) {
         for (int i = start; i < (int)num.size(); i++) {
             if (num[i] == target) return true;
         }
         return false;
     }
     void twoSum(vector<int> &num, int start, int target,
		    vector<vector<int>>& result) {
         if (num.size() - start < 2) return;
         unsigned int i = start;
         unsigned int j = num.size() - 1;
         while (j > i) {
             if (i > start && num[i] == num[i-1]) {
                 i++; 
                 continue;
             }
             int tmp = num[i]+num[j];
             if (tmp == target) {
		 vector<int> v = {num[i], num[j]};
		 result.push_back(v);
		 i++; j--;
                 continue;
	     }
             if (tmp > target) {
                 j--;
             }
             else {
                 i++;
             }
         }
     }

     void threeSum(vector<int> &num, int start, int target,
                    vector<vector<int>>& result) {
	 unsigned int len = num.size();
         if (num.size() - start < 3) return;
         if (target < num[start]+num[start+1]+num[start+2]) return; 
         if (target > num[len-1]+num[len-2]+num[len-3]) return;

	 for (unsigned int i = start; i < len-2; i++) {
             unsigned int j = i;
             while (j < len && num[j] == num[i]) j++;
             if (j-i >= 3) {
                 if (num[i] * 3 == target) {
                     result.push_back({num[i], num[i], num[i]});
                 }
             }
             if (j-i >= 2) {
                 if (oneSum(num, j, target-num[i]*2)) {
                     result.push_back({num[i], num[i], target-num[i]*2});
                 }
             }
	     vector<vector<int>> vvi;
	     twoSum(num, j, target-num[i], vvi);
             for (unsigned int k = 0; k < vvi.size(); k++) {
                 vector<int> v = vvi[k];
                 v.insert(v.begin(), num[i]);
                 result.push_back(v);
             }
             i = j-1;
	 }
     }

     vector<vector<int> > fourSum(vector<int> &num, int target) {
         unsigned int len = num.size();
         vector<vector<int>> ret;

         if (len < 4) return ret;
         sort(num.begin(), num.end());
         if (num[0]+num[1]+num[2]+num[3] > target) return ret;
         if (num[len-1]+num[len-2]+num[len-3]+num[len-4] < target) return ret;

         unsigned int i;
         for (i = 0; i < len-3; i++) {
             unsigned int j = i;
             while (j < len && num[j] == num[i]) j++;
             if (j-i >= 4) {
                 if (num[i]*4 == target) {
                     ret.push_back({num[i], num[i], num[i], num[i]});
                 }
             }
             if (j-i >= 3) {
                 if (oneSum(num, j, target-num[i]*3)) {
                     ret.push_back({num[i], num[i], num[i], target-num[i]*3});
                 }
             }
             if (j-i >= 2) {
                 vector<vector<int>> vvi;
                 twoSum(num, j, target-num[i]*2, vvi);
                 for (unsigned int k = 0; k < vvi.size(); k++) {
                     vector<int> v = vvi[k];
                     v.insert(v.begin(), num[i]);
                     v.insert(v.begin(), num[i]);
                     ret.push_back(v);
                 }
             }
             vector<vector<int>> vvi;
             threeSum(num, j, target-num[i], vvi);
             for (unsigned int k = 0; k < vvi.size(); k++) {
                 vector<int> v = vvi[k];
                 v.insert(v.begin(), num[i]);
                 ret.push_back(v);
             }
             i = j-1;
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> num = {1,0,-1,0,-2,2, 0, 0, 3, -2, 3, -3, -3, 4, -4};
    vector<vector<int>> ret;

    ret = s.fourSum(num, 0);
    for (unsigned int i = 0; i < ret.size(); i++) {
	for (unsigned int j = 0; j < ret[i].size(); j++) {
	    cout << ret[i][j] << ",";
	}
	cout << endl;
    }
    cout << endl;

    num = {-4,-3,-2,-1,0,0,1,2,3,4};
    ret = s.fourSum(num, 0);
    for (unsigned int i = 0; i < ret.size(); i++) {
	for (unsigned int j = 0; j < ret[i].size(); j++) {
	    cout << ret[i][j] << ",";
	}
	cout << endl;
    }
    cout << endl;

    num = {-7,-5,0,7,1,1,-10,-2,7,7,-2,-6,0,-10,-5,7,-8,5};
    ret = s.fourSum(num, 28);
    for (unsigned int i = 0; i < ret.size(); i++) {
	for (unsigned int j = 0; j < ret[i].size(); j++) {
	    cout << ret[i][j] << ",";
	}
	cout << endl;
    }
    cout << endl;

}

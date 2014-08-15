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
     // find index that is 0, or closest to 0
     unsigned int findIndexOfZero(vector<int> &num) {
         unsigned int start = 0;
         unsigned int end = num.size();
         unsigned int mid = (start+end)/2;

         while (start < end) {
             if (num[mid] > 0) {
                 end = mid-1;
             }
             else if (num[mid] < 0) {
                 start = mid+1;
             }
             else {
                 return mid;
             }
             mid = (start+end) / 2;
         }

         return num[mid] > 0 ? mid-1 : mid;
     }

     void twoSum(vector<int> &num, int start, int end, vector<vector<int>>&
                 res, int sum) {
         unsigned int i = start;
         unsigned int j = end;
         while (i < j) {
             if ( i > 0 && num[i] == num[i-1]) {
                 i++;
                 continue;
             }

             int tmp = num[i]+num[j];
             if (tmp == sum && (num[i] || num[j])) {
                 vector<int> v;
                 if (sum > 0) {
                    v.push_back(-sum);
                 }
                 v.push_back(num[i]);
                 if (!sum) {
                     v.push_back(0);
                 }
                 v.push_back(num[j]);
                 if (sum < 0) {
                     v.push_back(-sum);
                 }
                 res.push_back(v);
                 i++; j--;
             }
             else if (tmp < sum) {
                 i++;
             }
             else {
                 j--;
             }
         }
     }

     vector<vector<int> > threeSum(vector<int> &num) {
         vector<vector<int>> ret;
         if (num.size() < 3) return ret;
         sort(num.begin(), num.end());
         if (num[0] > 0 || num[num.size()-1] < 0) return ret;
         unsigned int mid = findIndexOfZero(num);

         // only three scenarios to get sum of 0:
         // 1. pos + 0 + neg/0+0+0
         // 2. pos + pos + neg
         // 3. pos + neg + neg

         int i = 0;
         int lastNeg = mid;
         int firstPos = mid+1;
         // 1. pos + 0 + neg/0+0+0
         if (!num[mid]) {
             while (lastNeg >= 0 && !num[lastNeg]) lastNeg--;
             while (firstPos < (int)num.size() && !num[firstPos]) firstPos++;
             if (firstPos-lastNeg > 3) ret.push_back({0,0,0});
             twoSum(num, 0, num.size()-1, ret, 0);
         }

         // 2. pos + pos + neg
         while (firstPos < (int) num.size() && i <= lastNeg) {
             if ( i > 0 && num[i] == num[i-1]) {
                 i++;
                 continue;
             }

             twoSum(num, firstPos, num.size() - 1, ret, num[i]*-1);
             i++;
         }

         // 3. pos + neg + neg
         i = firstPos;
         while (lastNeg >= 0 && i < (int)num.size()) {
             if (i > firstPos && num[i] == num[i-1]) {
                 i++;
                 continue;
             }

             twoSum(num, 0, lastNeg, ret, num[i] * -1);
             i++;
         }
         return ret;
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

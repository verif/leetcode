/*
   Given an array S of n integers, find three integers in S such that the sum
   is closest to a given number, target. Return the sum of the three integers.
   You may assume that each input would have exactly one solution.

   For example, given array S = {-1 2 1 -4}, and target = 1.
   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <vector>
#include <iostream>
#include <algorithm> // for sort/abs
using namespace std;

class Solution {
public:
     int twoSumClosest(vector<int> &num, unsigned int start, int target) {
         unsigned int i = start;
         unsigned int j = num.size() - 1;
         int ret = num[0] + num[1];

         while (j > i) {
             int tmp = num[i]+num[j];
             ret = abs(ret-target) > abs(tmp-target) ? tmp : ret;
             if (tmp == target) return tmp;
             if (tmp > target) {
                 j--;
             }
             else {
                 i++;
             }
         }
         return ret;
     }

     int threeSumClosest(vector<int> &num, int target) {
         unsigned int len = num.size();
         if (len < 3) return -1;
         sort(num.begin(), num.end());

         if (target < num[0]+num[1]+num[2]) return  num[0]+num[1]+num[2];
         if (target > num[len-1]+num[len-2]+num[len-3]) return
             num[len-1]+num[len-2]+num[len-3];

         int ret = num[0]+num[1]+num[2];
         for (unsigned int i = 0; i < len-2; i++) {
             int tmp = twoSumClosest(num, i+1, target-num[i]);
             ret = abs(ret-target) > abs(tmp+num[i]-target) ? tmp+num[i] : ret;
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> num = {-1,-2,4, -2, -3, -2, 7};
    int ret;

    ret = s.threeSumClosest(num, 7);
    cout << ret << endl;
}


/*
   Given n non-negative integers a1, a2, ..., an, where each represents a point
   at coordinate (i, ai). n vertical lines are drawn such that the two
   endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
   with x-axis forms a container, such that the container contains the most
   water.

Note: You may not slant the container.
*/

#include <vector>
#include <iostream>
#include <algorithm> // for 'min'/'max'
using namespace std;

class Solution {
public:
     int maxArea(vector<int> &height) {
         unsigned int len = height.size();
         if (len < 2) return 0;
         int ret = 0;
         int i = 0;
         int j = len-1;

         while (i < j) {
             ret = max(ret, min(height[i], height[j])*(j-i));
             if (height[i] < height[j]) {
                 int k = i+1;
                 while (k < j && height[k] < height[i]) k++;
                 i = k;
             }
             else {
                 int k = j-1;
                 while (k > i && height[k] < height[j]) k--;
                 j = k;
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> height = {1, 3, 5, 5, 7, 9};
    int ret = s.maxArea(height);

    cout << ret << endl;

    height = {3,2,1,3};
    cout << s.maxArea(height) << endl;
}

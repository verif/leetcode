/*
   Given n non-negative integers representing the histogram's bar height where
   the width of each bar is 1, find the area of largest rectangle in the
   histogram.





   Above is a histogram where width of each bar is 1, given height =
   [2,1,5,6,2,3].





   The largest rectangle is shown in the shaded area, which has area = 10 unit.

   For example,
   Given height = [2,1,5,6,2,3],
   return 10.
*/

#include <iostream>
#include <stack>
#include <algorithm> // std::max
using namespace std;

class Solution {
public:
     int largestRectangleArea(vector<int> &height) {
         int total = height.size();
         if (!total) return 0;
         int ret = 0;
         stack<int> stk;

         for (int i = 0; i < total; i++) {
             if (stk.empty() || height[stk.top()] < height[i]) {
                 stk.push(i);
             }
             else {
                 while (!stk.empty() && height[stk.top()] >= height[i]) {
                     int h = stk.top();
                     stk.pop();
                     int idx = stk.empty() ? -1 : stk.top();
                     ret = max(ret, (i-idx-1)*height[h]);
                 }
                 stk.push(i);
             }
         }

         while (!stk.empty()) {
             int h = stk.top();
             stk.pop();
             int idx = stk.empty() ? -1 : stk.top();
             ret = max(ret, (total-idx-1)*height[h]);
         }
         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> height = {2,1,5,6,2,3};
    int ret;

    ret = s.largestRectangleArea(height);
    cout << ret << endl;

    height = {};
    ret = s.largestRectangleArea(height);
    cout << ret << endl;

    height = {1};
    ret = s.largestRectangleArea(height);
    cout << ret << endl;

    height = {1,2,3};
    ret = s.largestRectangleArea(height);
    cout << ret << endl;

    height = {3,2,1};
    ret = s.largestRectangleArea(height);
    cout << ret << endl;

    height = {1,1};
    ret = s.largestRectangleArea(height);
    cout << ret << endl;
}

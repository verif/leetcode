/*
   Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
   containing all ones and return its area.
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
     int maximalRectangle(vector<vector<char> > &matrix) {
         int numRows = matrix.size();
         if (!numRows) return 0;
         int numCols = matrix[0].size();

         vector<vector<int>> heights;
         int i, j;
         int ret = 0;

         for (i = 0; i < numRows; i++) {
             vector<int> row;
             for (j = 0; j < numCols; j++) {
                 int val = matrix[i][j] == '0' ? 0 : 1;
                 int h = i ? heights[i-1][j] + val : val;
                 h = !val ? 0 : h;
                 row.push_back(h);
             }
             int rowMax = largestRectangleArea(row);
             ret = max(ret, rowMax);
             heights.push_back(row);
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix = {{'1','1','1','0'}, {'1','1','1','0'}, {'1','1','1','1'}, {'1','1','1','1'}};
    int ret;

    ret = s.maximalRectangle(matrix);
    cout << ret << endl;

    matrix = {{'0'}};
    ret = s.maximalRectangle(matrix);
    cout << ret << endl;
}

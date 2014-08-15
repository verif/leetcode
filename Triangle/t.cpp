/*
   Given a triangle, find the minimum path sum from top to bottom. Each step
   you may move to adjacent numbers on the row below.
   For example, given the following triangle
   [
        [2],
       [3,4],
      [6,5,7],
     [4,1,8,3]
   ]
   The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is
the total number of rows in the triangle.
*/

#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

// Using top down traversal to solve with O(n) space and O(n2) time
class Solution {
public:
     int minimumTotal(vector<vector<int> > &triangle) {
         int rows = triangle.size();
         if (!rows) return 0;
         vector<int> minPath = triangle[0];
         int ret = -1;

         // Now process each row top down
         for (int i = 1; i < rows; i++) {
             // there are (i+1) elements in current row

             vector<int> orgMinPath = minPath;
             // handle first entry
             minPath[0] = orgMinPath[0] + triangle[i][0];

             for (int j = 1; j < i; j++) {
                 minPath[j] = orgMinPath[j-1] > orgMinPath[j] ? orgMinPath[j] +
                     triangle[i][j] : orgMinPath[j-1] + triangle[i][j];
             }

             // handle last entry
             minPath.push_back(orgMinPath[i-1] +  triangle[i][i]);
         }

         ret = minPath[0];
         for (int i = 1; i < rows; i++) {
             ret = ret > minPath[i] ? minPath[i] : ret;
         }
         return ret;
     }
};

int main()
{
    Solution s;
    int ret;
    vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4, 1, 8, 3}};

    ret = s.minimumTotal(triangle);

    cout << ret << endl;

    return 0;
}

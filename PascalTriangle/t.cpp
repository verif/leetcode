/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     vector<vector<int> > generate(int numRows) {
         vector<vector<int>> ret;

         for (int i = 0; i < numRows; i++) {
             // i+1 number of entries this row
             vector<int> row(i+1);
             if (!i) {
                 row[i] = 1;
             }
             else {
                 row[0] = ret[i-1][0];
                 row[i] = ret[i-1][i-1];
                 for (int j = 1; j < i; j++) {
                     row[j] = ret[i-1][j-1] + ret[i-1][j];
                 }
             }
             ret.push_back(row);
         }
         return ret;
     }
};

static void printTriangle(vector<vector<int>> &triangle)
{
    int len = triangle.size();
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < (len - i); j++) cout << " ";
        cout << "[";
        for (j = 0; j < triangle[i].size(); j++) {
            cout << triangle[i][j];
            if (j != triangle[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != len-1) cout << ",";
        cout << endl;
    }
}

int main()
{
    Solution s;
    vector<vector<int>> ret;

    ret = s.generate(10);

    printTriangle(ret);

    return 0;
}

/*
   Given an index k, return the kth row of the Pascal's triangle.
   For example, given k = 3,
   Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     vector<int> getRow(int rowIndex) {
         vector<int> ret(rowIndex+1);
         vector<int> row(rowIndex+1);

         row[0] = 1;
         ret = row;
         for (int i = 1; i <= rowIndex; i++) {
             ret[0] = 1;
             for (int j = 1; j < i; j++) {
                 ret[j] = row[j-1]+row[j];
             }
             ret[i] = 1;
             row = ret;
         }

         return ret;
     }
};

static void printRow(vector<int> &row)
{
    for (int i = 0; i < row.size(); i++) {
        cout << row[i] << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> ret;

    ret = s.getRow(3);

    printRow(ret);

    return 0;
}

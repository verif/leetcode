/*
   Say you have an array for which the ith element is the price of a given
   stock on day i.

   If you were only permitted to complete at most one transaction (ie, buy one
   and sell one share of the stock), design an algorithm to find the maximum
   profit.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int maxProfit(vector<int> &prices) {
         int curMin = 0;
         int curMax = 0;
         int ret = 0;

         for (int i = 1; i < prices.size(); i++) {
             if (prices[i] < prices[curMin]) {
                 curMin = i;
                 curMax = i;
             }
             else if (prices[i] > prices[curMax]) {
                 curMax = i;
                 int tmp = prices[curMax] - prices[curMin];
                 ret = ret > tmp ? ret : tmp;
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> prices = {1, 3, 0, 1};
    int ret;

    ret = s.maxProfit(prices);

    cout << ret << endl;
}

/*
   Say you have an array for which the ith element is the price of a given
   stock on day i.

   Design an algorithm to find the maximum profit. You may complete as many
   transactions as you like (ie, buy one and sell one share of the stock
   multiple times). However, you may not engage in multiple transactions at the
   same time (ie, you must sell the stock before you buy again).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int maxProfit(vector<int> &prices) {
         if (prices.size() < 2) return 0;
         int ret = 0;
         for (unsigned int i = 0; i < prices.size() - 1; i++) {
             if (prices[i] < prices[i+1]) {
                 ret += (prices[i+1] - prices[i]);
             }
         }
         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> prices = {};
    int ret;

    ret = s.maxProfit(prices);

    cout << ret << endl;

    return 0;
}

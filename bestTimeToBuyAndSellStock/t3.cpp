/*
   Say you have an array for which the ith element is the price of a given
   stock on day i.

   Design an algorithm to find the maximum profit. You may complete at most two
   transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell
the stock before you buy again).
*/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// Use dynamic programming to solve it in O(n) time
class Solution {
public:
     int maxProfit(vector<int> &prices) {
	 int len = prices.size();
         if (len < 2) return 0;
	 int ret = 0;
	 int leftMax[len];
	 int rightMax[len];
	    
	 // compute leftMax/rightMax;
         leftMax[0] = 0;
         rightMax[len-1] = 0;
	 int l1 = 0;
	 int r1 = len-1;
	 for (int i = 1; i < len; i++) {
	     leftMax[i] = leftMax[i-1];
	     if (prices[i] < prices[l1]) {
		 l1 = i;
	     }
	     else {
		 int tmp = prices[i] - prices[l1];
		 leftMax[i] = leftMax[i] > tmp ? leftMax[i] : tmp;
	     }

	     int j = len-i- 1;
             rightMax[j] = rightMax[j+1];
	     if (prices[j] > prices[r1]) {
		 r1 = j;
	     }
	     else {
		 int tmp = prices[r1] - prices[j];
		 rightMax[j] = rightMax[j] > tmp ? rightMax[j] : tmp;
	     }
	 }

	 for (int i = 0; i < len; i++) {
	     int tmp = leftMax[i] + rightMax[i];
	     ret = ret > tmp ? ret : tmp;
	 }

	 return ret;
     }
};

int main()
{
    Solution s;
    vector<int> prices = {1, 5, 5, 2, 6};
    int ret = s.maxProfit(prices);
    cout << ret << endl;

    return 0;
}

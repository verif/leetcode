/*
   You are climbing a stair case. It takes n steps to reach to the top.

   Each time you can either climb 1 or 2 steps. In how many distinct ways can
   you climb to the top?
*/

#include <iostream>
using namespace std;

class Solution {
public:
     int climbStairs(int n) {
         int p[n+1];

         p[0] = 1;
         p[1] = 1;
         for (int i = 2; i <= n; i++) {
             p[i] = p[i-1]+p[i-2]; 
         }

         return p[n];
     }
};

int main()
{
    Solution s;
    int ret;

    ret = s.climbStairs(5);
    cout << ret << endl;
}

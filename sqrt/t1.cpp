/*
   Implement int sqrt(int x).

   Compute and return the square root of x.
*/

#include <iostream>
using namespace std;

class Solution {
public:
     int sqrt(int x) {
         if (x < 0) return -1;
         if (!x) return 0;

         int start = 1;
         int end = x;
         long long mid = ((long long)start+end)/2;
         long long res;
         while (start < end) {
             res = mid * mid;
             if (res == x) return mid;
             else if (res > x) end = mid - 1;
             else start = mid+1;
             mid = ((long long)start+end)/2;
         }

         res = mid * mid;
         return res > x ? mid - 1 : mid;
     }
};

int main()
{
    Solution s;
    int ret;

    ret = s.sqrt(2);
    cout << ret << endl;

    ret = s.sqrt(2147483647);
    cout << ret << endl;

    ret = s.sqrt(2147395599);
    cout << ret << endl;
}


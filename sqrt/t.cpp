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
         int i = x;
         int numDigits = 0;
         while (i > 0) {
             i /= 10;
             numDigits++;
         }
         int start = 1;
         numDigits = (numDigits-1)/2;
         while (numDigits) {
             start *= 10;
             numDigits--;
         }
         int begin = start;
         int end = start * 10;
         i = (begin+end)/2;
         while (i > begin && i < end) {
             unsigned long long res = i*i;
             if (res > x) {
                 end = i;
                 i = (begin+end)/2;
             }
             else if (res < x) {
                 begin = i;
                 i = (begin+end)/2;
             }
             else return i;
         }
         
         return i;
     }
};

int main()
{
    Solution s;
    int ret;

    ret = s.sqrt(2);
    cout << ret << endl;
    ret = s.sqrt(3);
    cout << ret << endl;
    ret = s.sqrt(2147395599);
    cout << ret << endl;
}


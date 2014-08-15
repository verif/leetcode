/*
Finonacci: recursive
*/

#include <iostream>
using namespace std;

class Solution {
public:
     int fibonacci(int n) {
         if (n < 1) return 0;
         int res[n+1];
         res[1] = 1;
         res[2] = 1;
         for (int i = 3; i <= n; i++) {
             res[i] = res[i-1] + res[i-2];
         }

         return res[n];
     }
};

int main()
{
    Solution s;
    cout << "5: " << s.fibonacci(5) << endl;
    cout << "55: " << s.fibonacci(55) << endl;
}

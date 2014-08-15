/*
Finonacci: recursive
*/

#include <iostream>
using namespace std;

class Solution {
public:
     int fibonacci(int n) {
         if (n < 1) return 0;
         int last1 = 1;
         int last2 = 1;
         for (int i = 3; i <= n; i++) {
             int tmp = last2;
             last2 = last1 + last2;
             last1 = tmp;
         }

         return last2;
     }
};

int main()
{
    Solution s;
    cout << "5: " << s.fibonacci(5) << endl;
    cout << "55: " << s.fibonacci(55) << endl;
}

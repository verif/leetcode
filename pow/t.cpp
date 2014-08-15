/*
   Implement pow(x, n).
*/

#include <iostream>
using namespace std;

class Solution {
public:
     double pow(double x, int n) {
         if (!n) return 1;
         int half = n < 0 ? (int)(((unsigned int)-n)/2): n/2;
         double result = pow(x, half);
         if (n % 2) { // odd number
             result = result * result * x;
         }
         else {
             result *= result;
         }

         return n < 0 ? 1/result : result;
     }
};

int main()
{
    Solution s;
    double result;

    result = s.pow(3.0, -1);
    cout << result << endl;
    result = s.pow(1.00, -2147483648);
    cout << result << endl;
    result = s.pow(1.1, 2147483647);
    cout << result << endl;
    result = s.pow(3.0, 0);
    cout << result << endl;
    result = s.pow(3.0, 1);
    cout << result << endl;
    result = s.pow(0, 3);
    cout << result << endl;
    result = s.pow(0, -3);
    cout << result << endl;
    result = s.pow(14.95, 3);
    cout << result << endl;
    result = s.pow(14.95, -3);
    cout << result << endl;
}

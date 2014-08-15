/*
   Divide two integers without using multiplication, division and mod operator.
*/

#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
     int divide(int dividend, int divisor) {
        unsigned a = (unsigned)abs(dividend);
        unsigned b = (unsigned)abs(divisor);
        if (a < b) return 0;
        int sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor
>0);
        long long unsigned res = 0, tmp = 0, rem = a;
        
        while (rem >= b) { rem >>= 1; res = res ? res << 1 : 1; tmp = tmp ? tmp
<< 1 : b;}
        res += divide(a-tmp, b);
        
        return sign ? -res : res;
     }
};

int main()
{
    Solution s;

    cout << "-2147483648/-3 " << (int) -2147483648/-3 << " " << s.divide(-2147483648, -3) << endl;
    cout << "2147483647/-2147483648 " << (int) 2147483647/-2147483648 << " " << s.divide(2147483647, -2147483648) << endl;
    cout << "2147483648/-2147483647 " << (int) 2147483648/-2147483647 << " " << s.divide(2147483648, -2147483647) << endl;
    cout << "2147483648/-2147483648 " << (int) 2147483648/-2147483648 << " " << s.divide(2147483648, -2147483648) << endl;
    cout << "10001000/1000 " << (int) 10001000/1000 << " " << s.divide(10001000, 1000) << endl;
    cout << "202/2 " << (int) 202/2 << " " << s.divide(202, 2) << endl;
    cout << "2147483648/1 " << (int) 2147483648/1 << " " << s.divide(2147483648, 1) << endl;
    cout << "2147483647/2 " << (int) 2147483647/2 << " " << s.divide(2147483647, 2) << endl;
    cout << "1/2147483648 " << 1/2147483648 << " " << s.divide(1, 2147483648) << endl;
    cout << "-2147483648/1 " << -2147483648/1 << " " << s.divide(-2147483648, 1) << endl;
    cout << "1/-2147483648 " << 1/-2147483648 << " " << s.divide(1, -2147483648) << endl;
    cout << "-1/1 " << -1/1 << " " << s.divide(-1, 1) << endl;
    cout << "-1/-1 " << -1/-1 << " " << s.divide(-1, -1) << endl;
    cout << "12/3 " << 12/3 << " " << s.divide(12, 3) << endl;
    cout << "12/-3 " << 12/-3 << " " << s.divide(12, -3) << endl;
    cout << "2/3 " << 2/3 << " " << s.divide(2, 3) << endl;
//    cout << "2/0 " << 2/0 << " " << s.divide(2, 0) << endl;
    cout << "0/2 " << 0/2 << " " << s.divide(0, 2) << endl;
    cout << "0123/03 " << 0123/03 << " " << s.divide(0123, 03) << endl;
    cout << "12/5 " << 12/5 << " " << s.divide(12, 5) << endl;
    cout << "1432452/435 " << 1432452/435 << " " << s.divide(1432452, 435) << endl;
}

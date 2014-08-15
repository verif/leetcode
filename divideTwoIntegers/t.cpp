/*
   Divide two integers without using multiplication, division and mod operator.
*/

#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
     string sdivide(string sdividend, string sdivisor) {
         string ret;
         int n = sdivisor.length();
         int m = sdividend.length();
         if (m < n) return ret;
         unsigned int dsor = atoi(sdivisor.c_str());
         string sub = sdividend.substr(0, n);
         unsigned int i = atoi(sub.c_str());
         if (i < dsor) {
             if (m == n) return ret;
             sub = sdividend.substr(0, n+1);
             i = atoi(sub.c_str());
         }
         int c = 0;
         while (i >= dsor) {
             i -= dsor;
             c++;
         }
         string prefix(1, (char)('0'+c));
         ostringstream os;
         if (i) {
             os << i;
         }
         sdividend.erase(0, sub.length());
         string remain = os.str();
         // insert '0' for number of carryovers to borrow
         int numZeros = 0;
         while (numZeros < (int)sdividend.length()) {
             remain.insert(remain.end(), sdividend[numZeros]);
             if ((unsigned int)atoi(remain.c_str()) >= dsor) break;
             numZeros++;
             prefix.insert(prefix.end(), '0');
         }
         if (i) sdividend.insert(0, os.str());

         ret = sdivide(sdividend, sdivisor);
         ret.insert(0, prefix);

         return ret;
     }

     int divide(int dividend, int divisor) {
         if (!divisor || !dividend) return 0;
         bool isNeg = (dividend < 0 && divisor > 0) || 
                      (dividend > 0 && divisor < 0);
         if (dividend < 0) dividend = -dividend;
         if (divisor < 0) divisor = -divisor;
         if ((unsigned int) dividend < (unsigned int) divisor) return 0;
         ostringstream os1, os2;
         os1 << (unsigned int)dividend;
         os2 << (unsigned int)divisor;
         string res = sdivide(os1.str(), os2.str());
         if (isNeg) res.insert(res.begin(), '-');

         return atoi(res.c_str());
     }
};

int main()
{
    Solution s;

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

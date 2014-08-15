/*
   Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <iostream>

class Solution {
public:
     int reverse(int x) {
         if (x >= -9 && x <= 9) return x;
         int ret = 0;
         while (x) {
             ret *= 10;
             ret += (x % 10);
             x /= 10;
         }

         return ret;
     }
};

int main()
{
    Solution s;
    std::cout << "123 " << s.reverse(123) << std::endl;
    std::cout << "-123 " << s.reverse(-123) << std::endl;
    std::cout << "100 " << s.reverse(100) << std::endl;
    std::cout << "1 " << s.reverse(1) << std::endl;
    std::cout << "-100 " << s.reverse(-100) << std::endl;
    std::cout << "-1 " << s.reverse(-1) << std::endl;
    std::cout << "13579 " << s.reverse(13579) << std::endl;
    std::cout << "-24608 " << s.reverse(-24608) << std::endl;
    std::cout << "-2147483648 " << s.reverse(-2147483648) << std::endl;
    std::cout << "2147483648 " << s.reverse(2147483648) << std::endl;
}


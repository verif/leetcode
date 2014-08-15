/*
   Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge,
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given
input specs). You are responsible to gather all the input requirements up
front.
*/

#include <iostream>
#include <stdlib.h>

class Solution {
public:
     int atoi(const char *str) {
         long long result = 0;
         if (!str) return 0;
         const char *p = str;
         bool isNeg = false;
         while (*p && *p == ' ') p++;
         if (*p == '-') {
             isNeg = true;
             p++;
         }
         else if (*p == '+') p++;
         while (*p) {
             if (*p < '0' || *p > '9') break;
             result = result * 10 + (*p - '0');
             p++;
         }

         if (result >= 2147483648) result = isNeg ? 2147483648 : 2147483647;
         return isNeg ? -result : result;
     }
};

int main()
{
    Solution s;
    const char* p;
    
    p = " +11191657170";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "2147483649";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "-2147483649";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "2147483648";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "-2147483648";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "  -0012a42";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "-   010";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "   010";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "000";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "+123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "-123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "++123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "-+123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "--123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "-0123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "0.123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "2.123";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "2e3";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = ".3";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "3.";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
    p = "1a2bc";
    std::cout << p << " " << s.atoi(p) << " expected: " << atoi(p) << std::endl;
}

/*
   Given a roman numeral, convert it to an integer.
   Input is guaranteed to be within the range from 1 to 3999.
*/

/*
   I    1
   V    5
   X    10
   L    50
   C    100
   D    500
   M    1,000

   the numeral I can be placed before V and X to make 4 units (IV) and 9 units
   (IX respectively)

   X can be placed before L and C to make 40 (XL) and 90 (XC respectively)

   C can be placed before D and M to make 400 (CD) and 900 (CM) according to
   the same pattern[5]
*/

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:
     int romanToInt(string s) {
         unsigned int len = s.length();
         if (!len) return 0;
         int ret = 0;
         for (unsigned int i = 0; i < len; i++) {
             char c = s[i];
             switch (c) {
                 case 'I':
                     if (i < len-1 && (s[i+1] == 'V' || s[i+1] == 'X')) {
                         if (s[i+1] == 'V') {
                             ret += 4;
                         }
                         else {
                             ret += 9;
                         }
                         i++;
                     }
                     else {
                         ret++;
                     }
                     break;
                 case 'V':
                     ret += 5;
                     break;
                 case 'X':
                     if (i < len-1 && (s[i+1] == 'L' || s[i+1] == 'C')) {
                         if (s[i+1] == 'L') {
                             ret += 40;
                         }
                         else {
                             ret += 90;
                         }
                         i++;
                     }
                     else {
                         ret += 10;
                     }
                     break;
                 case 'L':
                     ret += 50;
                     break;
                 case 'C':
                     if (i < len-1 && (s[i+1] == 'D' || s[i+1] == 'M')) {
                         if (s[i+1] == 'D') {
                             ret += 400;
                         }
                         else {
                             ret += 900;
                         }
                         i++;
                     }
                     else {
                         ret += 100;
                     }
                     break;
                 case 'D':
                     ret += 500;
                     break;
                 case 'M':
                     ret += 1000;
                     break;
                 default:
                     assert(0);
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;

    cout << "MMCCCXCIX " << s.romanToInt("MMCCCXCIX") << endl;
    cout << "I " << s.romanToInt("I") << endl;
    cout << "II " << s.romanToInt("II") << endl;
    cout << "IV " << s.romanToInt("IV") << endl;
    cout << "VI " << s.romanToInt("VI") << endl;
    cout << "V " << s.romanToInt("V") << endl;
    cout << "MCMLIV " << s.romanToInt("MCMLIV") << endl;
    cout << "MCMXC " << s.romanToInt("MCMXC") << endl;
    cout << "MMXIV " << s.romanToInt("MMXIV") << endl;
}


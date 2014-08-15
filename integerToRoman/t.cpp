/*
   Given an integer, convert it to a roman numeral.

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

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
     string intToRoman(int num) {
         string ret;
         int i;
         int digit = num/1000;
         for (i = 0; i < digit; i++) {
             ret.push_back('M');
         }

         num = num - (num/1000)*1000;
         digit = num/100;
         if (digit == 9) {
             ret.push_back('C');
             ret.push_back('M');
         }
         else if (digit == 4) {
             ret.push_back('C');
             ret.push_back('D');
         }
         else {
             if (digit >= 5) {
                 ret.push_back('D');
                 digit -= 5;
             }
             for (i = 0; i < digit; i++) {
                 ret.push_back('C');
             }
         }

         num = num - (num/100)*100;
         digit = num/10;
         if (digit == 9) {
             ret.push_back('X');
             ret.push_back('C');
         }
         else if (digit == 4) {
             ret.push_back('X');
             ret.push_back('L');
         }
         else {
             if (digit >= 5) {
                 ret.push_back('L');
                 digit -= 5;
             }
             for (i = 0; i < digit; i++) {
                 ret.push_back('X');
             }
         }

         num = num - (num/10)*10;
         digit = num;
         if (digit == 9) {
             ret.push_back('I');
             ret.push_back('X');
         }
         else if (digit == 4) {
             ret.push_back('I');
             ret.push_back('V');
         }
         else {
             if (digit >= 5) {
                 ret.push_back('V');
                 digit -= 5;
             }
             for (i = 0; i < digit; i++) {
                 ret.push_back('I');
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;

    cout << "MMCCCXCIX " << s.intToRoman(2399) << endl;
    cout << "I " << s.intToRoman(1) << endl;
    cout << "II " << s.intToRoman(2) << endl;
    cout << "IV " << s.intToRoman(4) << endl;
    cout << "VI " << s.intToRoman(6) << endl;
    cout << "V " << s.intToRoman(5) << endl;
    cout << "MCMLIV " << s.intToRoman(1954) << endl;
    cout << "MCMXC " << s.intToRoman(1990) << endl;
    cout << "MMXIV " << s.intToRoman(2014) << endl;
}


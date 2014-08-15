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
    void intToRomanAux(string &ret, int digit, char c) {
        if (digit == 9) {
            if (c == 'C') ret.insert(ret.size(), "CM");
            else if (c == 'X') ret.insert(ret.size(), "XC");
            else ret.insert(ret.size(), "IX");
        }
        else if (digit == 4) {
            if (c == 'C') ret.insert(ret.size(), "CD");
            else if (c == 'X') ret.insert(ret.size(), "XL");
            else ret.insert(ret.size(), "IV");
        }
        else {
            if (digit >= 5) {
                if (c == 'C') ret.push_back('D');
                else if (c == 'X') ret.push_back('L');
                else ret.push_back('V');
                digit -= 5;
            }
            for (int i = 0; i < digit; i++) ret.push_back(c);
        }
    }
    string intToRoman(int num) {
        string ret;
        if (num >= 1000) ret.insert(ret.end(), num/1000, 'M');
        num -= (num/1000) * 1000;
        intToRomanAux(ret, num/100, 'C');
        num -= (num/100) * 100;
        intToRomanAux(ret, num/10, 'X');
        num -= (num/10) * 10;
        intToRomanAux(ret, num, 'I');
        
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


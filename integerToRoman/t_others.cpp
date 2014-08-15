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
      // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int n_M = int(num/1000);
        num = num%1000;
        int n_D = int(num/500);
        num = num%500;
        int n_C = int(num/100);
        num = num%100;
        int n_L = int(num/50);
        num = num%50;
        int n_X = int(num/10);
        num = num%10;
        int n_V = int(num/5);
        num = num%5;
        int n_I = int(num/1);
         
        return string(n_M,'M')+string(n_D,'D')+string(n_C,'C')+string(n_L,'L')+string(n_X,'X')+string(n_V,'V')+string(n_I,'I');
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


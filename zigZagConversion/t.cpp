/*
   The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
   of rows like this: (you may want to display this pattern in a fixed font for
   better legibility)
   P   A   H   N
   A P L S I I G
   Y   I   R

   And then read line by line: "PAHNAPLSIIGYIR"
   Write the code that will take a string and make this conversion given a
   number of rows:
   string convert(string text, int nRows);
   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     string convert(string s, int nRows) {
         if (nRows < 2) return s;
         vector<string> strRows(nRows);
         string ret;
         bool isDown = true;
         int col = 0;
         int row = 0;

         for (unsigned int i = 0; i < s.length(); i++) {
             strRows[row].push_back(s[i]);
             if (isDown) {
                 if (row == nRows-1) {
                     isDown = false;
                     row--;
                     col++;
                 }
                 else {
                     row++;
                 }

             }
             else {
                 if (row == 0) {
                     isDown = true;
                     row++;
                 }
                 else {
                     row--;
                     col++;
                 }
             }
         }

         for (int i = 0; i < nRows; i++) {
             ret.insert(ret.end(), strRows[i].begin(), strRows[i].end());
         }
         return ret;
     }
};

int main() {
    Solution s;
    string ret;
    string str = "PAYPALISHIRING";

    ret = s.convert(str, 3);
    cout << ret << endl;
}
